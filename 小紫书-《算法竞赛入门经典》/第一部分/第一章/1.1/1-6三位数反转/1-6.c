#include<stdio.h>

//不要使用reverse1()，不能解决250的情况

int reverse1(int a){
    printf("-->%d%d%d \n",a%10,a/10%10,a/100);
    printf("reverse1()不能解决xx0，x00的情况，通过加法的方式来消除这种情况\n");
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
