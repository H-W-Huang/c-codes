#include<stdio.h>
int main()
{
    int a[6]={123,132,213,231,321,312},i;
    for(i=0;i<6;i++)
    {
        printf("%d %d %d \n",a[i],a[i]*2,a[i]*3);
    }
    return 0;
}