//  C  二进制回文质数

// Time Limit:1000MS  Memory Limit:65535K
// 题型: 编程题   语言: 无限制
// 描述

// 一个十进制正整数转化为二进制数，如果该二进制数是回文的（即从左到右拼写同从右到左拼写相同），则我们称这样的正整数为
// 二进制回文数，若该数又是一个质数，则称为二进制回文质数。
// 例如17的二进制是10001，17为二进制回文质数

// 现由键盘输入两个正整数a与b(a<=b)，问a到b范围内（包括a与b)有多少个二进制回文质数。

// 输入格式

// 两个正整数a和b，两数由一个空格分隔
// 输出格式

// 二进制回文质数的个数
// 输入样例

// 3 10
// 输出样例

// 3
// Provider

// admin

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int Is_prime(int n)
{
    if(n==1||n==0) return 0;
    int m;
    for(m=2;m<=n/2;m++)
        if(n%m==0) break;
    if(m>n/2) return 1;
    return 0;
} 

int Is_huiwen(int a[],int n)
{
    int i,j;
    for(i=0,j=n-1;i<=j;i++,j--)
        if(a[i]!=a[j]) break;
    if(i>j) return 1;
    return 0;
} 

int Convert2Binary(int n,int a[])
{
    int i=0,j;
    while(n!=0)
    {
        a[i++]=n%2;
        // printf("%d\n",n);
        // printf("i==%d\n",i);
        n=n/2;
    }
    //，for(j=i-1;j>=0;j--) printf("%d\n", a[j]);
    return i;
}

int main()
{
    // int a[5]={1,0,1,0,1};
    // if(Is_huiwen(a,5))cout<<"Yes"<<endl;else cout<<"No"<<endl;
    int num[1000],i,j,k,c=0;
    // i=Convert2Binary(16,a);
    // for(j=i-1;j>=0;j--) printf("%d\n", a[j]);
    int a,b;
    scanf("%d%d",&a,&b);
    for(k=a;k<=b;k++)
    {
        i=Convert2Binary(k,num);
        if(Is_huiwen(num,i)&&Is_prime(k)) c++;
    }
    printf("%d\n", c);
    return 0;
}