/*
 * @Description: ��ϰcout
 * @Author: Xjing An
 * @Date: 2019-09-24 09:31:54
 * @LastEditTime: 2019-10-03 10:09:11
 * @LastEditors: Please set LastEditors
 */
#include <iostream> //���ļ��е����������������У���python��import����,/ iosteram(input&out stream)�а���������������ĺ���
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <windows.h> //window�����ն�
using namespace std;



int main()
{
    //exp18 ָ������������
    double score[] {11, 22, 33, 44, 55};
    double *ptr_score = score;
    
    for (int i = 0; i < 5; i++){
        cout << *ptr_score++ << endl;
    }
    //���������Ǿ���������׵�ַ
    cout << sizeof(score) << "\t" << sizeof(ptr_score) << endl;
    cout << ptr_score[3] << endl;
    // exp17ָ��--------------------------------------
    /**
     * ָ����һ��ֵΪ�ڴ��ַ�ı����������ݶ���
     * 
     * */
    double num17 = 1024.5;
    //����һ��ָ�룬ָ��num17����
    double* ptr_num17 = &num17;
    double &ref_num17 = num17;
    cout << "ptr_num is Value:" << ptr_num17 << "\t" << &num17 << "\t"<< ref_num17 <<  endl;
    cout << "ptr_num17 ָ��ռ��ֵ��" << *ptr_num17 << endl;

    //exp16 ����--------------------------------------
    int num16[] = {1, 2, 4, 'c', 231231};
    cout << num16[2] << endl;
    // ��̬¼����Ϣ����ֵ
    const int N1 = 5;
    int num161[N1];

    for (int i = 0; i < sizeof(num161) / sizeof(int); i++){
        cout << "�������" << (i+1) << endl;
        cin >> num161[i];
    }
    for (int i = 0; i<sizeof(num161) / sizeof(int); i++){
        cout << num161[i] << endl;
    }


    //exp15-------------------------------------------
    //break ����ѭ�� continue�����´�ѭ��


    //exp14-------------------------------------------
    //for 
    /**
     * for(���ʽ1�����ʽ2�����ʽ3){
          ��䣻
    }*/
    const int N = 20;
    for (int i=0; i<N; i++){
        cout << "zaibiekangqiao"<< endl;
        if (i == 6){
            break;
        }
    }

    // exp13------------------------------------------
    // while
    int i = 0;  //ѭ�������ĳ�ʼֵ
    int sum = 0; //���������ۼӺ͵ı���
    while (i <= 100) //ѭ������������
    {
        cout << "-----" << endl;
        sum = sum + i; //�ۼ�
        i++;    //ѭ����������
        cout << sum << endl;
    }
    
        
    //exp12-------------------------------------------
    int num0 = 5;
    cout << sizeof(num0++) << endl;  //4
    cout << num0 << endl;            //5
    //exp11 ---------------------------------------
    // �˵�ѡ��
    // switch(���ʽ){case ����1�� ��䣻break; } ����
    int choice = 1;
    switch (choice)
    {
    case 1:
        cout << 1 << endl;
        break;
    case 2:
        cout << 2 << endl;
        break;
    case 3:
        cout << 3 << endl;
        break;
    
    default:
        break;
    }
    // exp10--------------------------------------
    // if  else if  else
    double flower_price; //���ĵ���
    cout << "����ǰ�ĺڰ�����ȥ�� ����֮��͸��һĨ���⣬�·�һ�ѵ�ȼ�Ļ�ѡ�����" << endl;
    cin >> flower_price;
    cout << flower_price << endl;
    //exp9----------------------------------------
    //if �������
    double price_louis = 35000.0;
    double price_hemes = 11044.5;
    double price_chanel = 1535.0;
    double total = 0;   // �ܼ�
    double zhekou = 0;  // �ۿ�
    total = price_chanel + price_hemes + price_louis;
    /**
     *��������������Ʒ��һ����Ʒ���۴���1000
     *��������Ʒ�ܶ����5000���ۿ���Ϊ30%
     *����û���ۿ�
     */
    if (price_louis > 1000 || price_hemes >1000 || price_chanel > 1000 || total > 5000){
        cout << "�ۿ�Ϊ0.3" << endl;
    }
    else{
        cout << "û���ۿ�" << endl;
    }

    //exp8----------------------------------------
    //����������ʽ����=����ֵ�����
    double salary = 3200.0; //���������
    int num9 = 1024;
    //���������
    num9 += 90;
    num9 -= 90;
    num9 /= 90;
    num9 *= 90;
    num9 %= 90;

    cout << num9 << endl;

    // ��ϵ�����>, <, >=, <=, ==, !=

    int a = 4, b = 16;
    cout << (a>b) << endl;
    cout << (a<b) << endl;

    // �߼������ a && b, a����b; a || b a��b; ! ��
    cout << ("---------------") <<endl;
    cout << (a && b) << endl;
    cout << (a||b) << endl;
    cout << (!a) <<endl;
    cout << ("---------------") <<endl;

    //λ�������&��|�� ~, ^, <<, >>, ��λ�롢�򡢷ǡ�������ƣ����ơ�(������ֹת��Ϊ�����ƣ��������ת��Ϊ��������)
    cout << ("---------------") <<endl;
    cout << (a & b) << endl;
    cout << (a|b) << endl;
    cout << (~a) <<endl;
    cout << (a^b) << endl;
    cout << (4<<a) << endl;
    cout << (a >> 4) << endl;
    cout << ("---------------") <<endl;
    



    //exp7-----------------------------------------
    // �Ӽ��˳���ȡģ
    double attack7 = 272;
    double attack8 = 250;
    double attack9 = 240;

    int num1 = -5, num2 =2;
    num1 = num2++ - --num2; //���ã�ǰ��
    cout << num1 << "\t" << num2 << endl;

    cout << num1 / num2 << endl; //����
    cout << num1 % num2 << endl; //ȡģ


    //cout << setfill("--") << endl;

    cout << setw(8) << attack7 << 
            setw(8) << attack8 <<
            setw(8) << attack9 << endl;
    //exp6-----------------------------------------
    // ������ϰ
    int num;
    char ch;
    cout << "������һ�����ݣ�";
    cin >> ch;
    cout << num << "\t" << ch << endl;


    //exp5-----------------------------------------
    // �޸��ն˱��⣺���ྲWorkSpace
    //SetConsoleTitle("���ྲ��WorkSpace");
    /**�˺�*/
    double value_attack = 57.88;
    /**�˺��ɳ�ֵ*/
    double grouth_attack = 4.5;
    /**��������*/
    double distance_attack = 27.58;
    
    cout << "���ƣ���������֮��"<<endl;
    cout << "�˺���" << value_attack << "(" << distance_attack << ")" <<endl;
    //exp4------------------------------------------
    //sizeof ���������������͵ĳ���
    cout <<sizeof(double)<<endl;
    cout <<sizeof(long double) << endl;
    cout <<sizeof(3.14f)<< endl;

    //exp3-------------------------------------------
    //����cout��ʾ����
    //1.ǿ����С���ķ�ʽ��ʾ
    cout << fixed;
    // 2.������ʾ�ľ���
    cout << setprecision(2);
    //���double���͵Ĳ���
    double double_num = 10.0 / 3.0;
    cout << double_num <<endl;

    //exp2-----------------------------------------
    //��֪Բ����İ뾶�͸ߣ���Բ��������
    const float PI = 3.141592653; //const ������һ��float���͵ĳ���
    float radius = 4.5f;
    float height = 90.0f;
    double volume = PI * pow(radius, 2);
    cout <<volume<<endl;


    //exp1---------------------------------------
    cout <<"hello world!!!"<<endl;
    cout <<"�����ҵ���Ʋ���ѽ\n";
    cout <<"��ô���ҵ����õľ�ҵ\n";
    cout <<"ѧϰC++\n";
    SetConsoleOutputCP(65001);
    system("pause");
    
    return 0;
}

//ÿ�����ռһ��
//ע��ֺţ�������
//ע��ֺţ��ո�
//
/*
 *�ļ�����
 *��  ����
 *��  �ߣ�
 *ʱ  �䣺
 *��  ����
*/