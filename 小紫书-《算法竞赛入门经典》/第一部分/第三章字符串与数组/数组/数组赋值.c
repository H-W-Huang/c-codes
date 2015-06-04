#include<stdio.h>
#include<string.h>
int main(){
    int a[20],b[20];
    int i;
    for(i=0;i<20;i++) a[i]=i;
    printf("a[2]=%d\n",a[2]);
    memcpy(b,a,sizeof(a));   //把a整个赋值给b
    printf("b[3]=%d\n",b[3]);
    return 0;
}