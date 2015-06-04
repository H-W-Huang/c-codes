#include<stdio.h>
int Is_ugly(int n)
{
    while(n%5==0) n/=5;
    while(n%3==0) n/=3;
    while(n%2==0) n/=2;
    if(n==1) return 1; else return 0;
}
int n[100000000];
int main()
{
    int i,j,T;
    for(i=1,j=1;i<=100000000;i++)
        if(!(Is_ugly(i))){n[j]=i;j++;}
    scanf("%d",&T);
    while(T--)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",n[x]);
    }
    return 0;
}