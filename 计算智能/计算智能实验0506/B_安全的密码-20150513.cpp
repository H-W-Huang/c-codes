//B  ��ȫ������
//
//Time Limit:1000MS  Memory Limit:65535K
//����: �����   ����: ������
//����
//
//С������������ʺ��ֱ����ˣ�Ϊ�˷�ֹ�Լ������ʺ��ٴα�����С��������ǿ���밲ȫ�����ڵĸ�������
//Ϊ�����׼�סÿ�θ��ĵ����룬С�������������붼��6λ���루ÿλ���������0-9������һ��������������������ͬ������
//��1�������а����Լ����������루�����ĺ�����ָ��������ȥ��0�������ɸ����룬ʣ�µ����밴˳���ܹ����������룩��
//��2���������������������ĺ�Ϊһ��������
//�����������������01314����021314��801314������������������
//
//��Ҫ���ɼ������벻����6λ���������룬�ɳ���������������Ĳ�ͬ6λ����ĸ���
//
//�����ʽ
//
//������6λ����������
//�����ʽ
//
//��ͬ��6λ����ĸ���
//��������
//
//01314
//�������
//
//17
//Provider
//
//admin
/******
����1.
    ����lucknum��λ�����õ�����Ҫ���Ե����ķ�Χ����ÿ����һһ����Ƿ������������ͨ��������ϼ������
    ˽��Ϊ���ַ�������ʵ�ָ��ӣ���ʱ�����ˡ�
����2.
    ö��
����3.
    �����ַ�����������
*******/




#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
//����Ƿ�Ϊ����
int Is_prime(int sum)
{
    int i;
    for(i=0;i<=sum/2;i++)
        if(sum%i==0) break;
    if(i>sum/2) return 1;
    else return 0;
}


////����luck_number�ĳ���
//int luck_number_length(int n)
//{
//    int length=0;
//    do{
//        n/=10;
//        length++;
//    }while(n!=0);
//    return length;
//}
//
////
int num_split(int n)
{
    int m,sum=0;
    do{
        m=n%10;
        n/=10;
        sum+=m;
    }while(n!=0);
    return sum;
}
//
//
////��������ĸ���
//int Amount_of_Passwords()
//{
//    int i,sum,luck_num=0,a[6],num_to_test=1,amount=0;
//    scanf("%d",&luck_num);
//    //��ʼö��
//    printf("The length of the luck number is %d \n",luck_number_length(luck_num));
//    for(i=0;i<=(6-luck_number_length(luck_num));i++)
//    {
//        num_to_test*=10;
//    }
//    num_to_test--;
//    printf("Numbers to be tested start from %d to 0\n",num_to_test);
//    while(num_to_test!=0)
//    {
//        if(!Is_prime(num_split(num_to_test)+num_split(luck_num)))
//        {
//
//        }
//    }
//    return amount;
//}
int Amount_of_Passwords()
{
    int luck_num=0,i=0;
    scanf("%d",&luck_num);
    for(i=0;i<=10000l;i++)
    {
        if(Is_prime(num_split(i))
        {
            for()
        }
    }

}

int main()
{
    Amount_of_Passwords();
    return 0;
}
