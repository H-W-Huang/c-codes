#include<stdio.h>

//��Ҫʹ��reverse1()�����ܽ��250�����

int reverse1(int a){
    printf("-->%d%d%d \n",a%10,a/10%10,a/100);
    printf("reverse1()���ܽ��xx0��x00�������ͨ���ӷ��ķ�ʽ�������������\n");
    return 0;
}

int reverse2(int a){
    int n=a%10*100+a/10%10*10+a/100;
    printf("-->%d\n",n);
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    reverse1(n);
    reverse2(n);
    return 0;
}
