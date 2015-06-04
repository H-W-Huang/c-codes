#include<stdio.h>
int devided_posibility(int n)
{
    int i,num=0;
    for(i=2;i<n/2;i++)
        if(n%i==0) num++;
    return num;
}

int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n", devided_posibility(n));
    }
    return 0;
}


