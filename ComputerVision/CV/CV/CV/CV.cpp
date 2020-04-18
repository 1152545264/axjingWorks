#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

#define pi 3.14159265

using namespace cv;
using namespace std;

//��ʾͼ�������
void ImgShow(Mat LSF, Mat Image)
{
	Mat src = (LSF < 0); //�ȵõ���ֵͼ
	Image.convertTo(Image, CV_8UC1);//ת������
	vector <vector<Point> > contours;
	vector <Vec4i> hierarchy;
	findContours(src, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
	drawContours(Image, contours, -1, cvScalar(255,0,0), 2);
	imshow("�ָ���", Image);
	waitKey(100);
}

//NeumannBound����
void NeumannBoundCond(Mat& LSF)
{
	int w = LSF.cols - 1;
	int h = LSF.rows - 1;
	LSF.at<float>(0, 0) = LSF.at<float>(2, 2);
	LSF.at<float>(h, 0) = LSF.at<float>(h - 2, 2);
	LSF.at<float>(0, w) = LSF.at<float>(2, w - 2);
	LSF.at<float>(h, w) = LSF.at<float>(h - 2, w - 2);

	for (int i = 0; i <= w; i++)
	{
		LSF.at<float>(0, i) = LSF.at<float>(2, i);
		LSF.at<float>(h, i) = LSF.at<float>(h - 2, i);
	}
	for (int i = 0; i <= h; i++)
	{
		LSF.at<float>(i, 0) = LSF.at<float>(i, 2);
		LSF.at<float>(i, w) = LSF.at<float>(i, w - 2);
	}
}

//�������ķ����Ǻ���
Mat atan(Mat LSF)  
{
	Mat dst(LSF.size(), LSF.type());
	for (int k = 0; k < LSF.rows; k++) //����
	{
		const float* inData = LSF.ptr<float>(k);
		float* outData = dst.ptr<float>(k);
		for (int i = 0; i < LSF.cols; i++)
			outData[i] = atan(inData[i]);
	}
	return dst;
}

Mat gradient_x(Mat input)
{
	Mat Ix(input.size(), input.type());
	for (int ncol = 0; ncol < input.cols; ncol++)
	{
		for (int nrow = 0; nrow < input.rows; nrow++)
		{
			if (ncol == 0) {
				Ix.at<float>(nrow, ncol) = input.at<float>(nrow, 1) - input.at<float>(nrow, 0);
			}
			else if (ncol == input.cols - 1) {
				Ix.at<float>(nrow, ncol) = input.at<float>(nrow, ncol) - input.at<float>(nrow, ncol - 1);

			}
			else
				Ix.at<float>(nrow, ncol) = (input.at<float>(nrow, ncol + 1) - input.at<float>(nrow, ncol - 1)) / 2;
		}
	}
	return Ix;
}

Mat gradient_y(Mat input)
{
	Mat Iy(input.size(), input.type());
	for (int nrow = 0; nrow < input.rows; nrow++)
	{
		for (int ncol = 0; ncol < input.cols; ncol++)
		{
			if (nrow == 0) {
				Iy.at<float>(nrow, ncol) = input.at<float>(1, ncol) - input.at<float>(0, ncol);
			}
			else if (nrow == input.rows - 1) {
				Iy.at<float>(nrow, ncol) = input.at<float>(nrow, ncol) - input.at<float>(nrow - 1, ncol);
			}
			else
				Iy.at<float>(nrow, ncol) = (input.at<float>(nrow + 1, ncol) - input.at<float>(nrow - 1, ncol)) / 2;
		}

	}
	return Iy;
}

void CV(Mat& LSF, Mat Img, float mu, float nu, float epison, float step)
{
	NeumannBoundCond(LSF); //�߽�����

	Mat Drc = (epison / pi) / (epison*epison+ LSF.mul(LSF)); //Dirac ����

	Mat Hea = 0.5*(1 + (2 / pi)*atan(LSF/epison)); //Heaviside ����

	//��������
	Mat Ix, Iy;
	Ix = gradient_x(LSF);
	Iy = gradient_y(LSF);
	Mat s;
	magnitude(Ix, Iy, s);//�ݶȵ�ģ
	Mat Nx = Ix / s;
	Mat Ny = Iy / s;
	Mat Nxx, Nyy;
	Nxx = gradient_x(Nx);
	Nyy = gradient_y(Ny);
	Mat cur = Nxx + Nyy;

	//������
	Mat Length = nu*Drc.mul(cur);

	//������
	Mat Lap;
	Laplacian(LSF, Lap, CV_32FC1);
	Mat Penalty = mu*(Lap - cur);

	//CV��
	Scalar S1;
	S1 = sum(Hea.mul(Img));
	Scalar S2;
	S2 = sum(Hea);
	float C1 = S1.val[0] / S2.val[0];
	Scalar S3;
	S3 = sum((1 - Hea).mul(Img));
	Scalar S4;
	S4 = sum((1 - Hea));
	float C2 = S3.val[0] / S4.val[0];
	Mat CVterm = Drc.mul((-1 * (Img - C1).mul(Img - C1) + 1 * (Img - C2).mul(Img - C2)));

	//�������
	LSF = LSF + step*(Length + Penalty + CVterm);
	uint i;
}


//������
int main()
{
	Mat Img = imread("1.bmp", 0); //����ͼ��
	Img.convertTo(Img, CV_32FC1);//ת������
	//��ʼ����
	Mat LSF = Mat::ones(Img.size(), CV_32FC1);;
	Rect roi(30, 30, 50, 50);
	LSF(roi) = -1;
	LSF = -LSF;
	ImgShow(LSF, Img);
	waitKey(1000);

	//��������
	float mu = 1;
	float nu = 0.003 * 255 * 255;
	int num = 50;
	float epison = 1;
	float step = 0.1;
	for (int n = 0; n < num; n++)
	{
		CV(LSF, Img, mu, nu, epison,step);//����
		if (n % 10 == 0)
			ImgShow(LSF, Img);
	}
	waitKey();
	//_CrtDumpMemoryLeaks();
	return 0;
}
