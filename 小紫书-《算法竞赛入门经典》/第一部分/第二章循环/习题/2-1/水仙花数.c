#include<stdio.h>
#define ERROR -1
int main(){
    int n;
    scanf("%d",&n);
    if(n<100||n>1000){
        printf("������һ����λ����\n" );
        printf("---->Tip:\n---->��ν��ĳ��Ϊˮ�ɻ���������������ڸ����ĸ�λ������ƽ�����\n---->���磺153=1��1+5��5+3��3\n");
        return  ERROR;
    }
    else
    {
        int a,b,c;
        a=n/100;
        b=n%100/10;
        c=n%10;
        printf("%d %d %d\n",a,b,c );
        a*a+b*b+c*c==n?printf("Yes!\n"):printf("No!\n");
    }
    printf("---->Tip:\n---->��ν��ĳ��Ϊˮ�ɻ���������������ڸ����ĸ�λ������ƽ�����\n---->���磺153=1��1+5��5+3��3\n");
    return 0;
}