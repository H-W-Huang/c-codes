#include<stdio.h>
#include<string.h>
int main(){
    int n,k,i,j;
    printf("分别输入灯的数量以及人的数量：\n");
    scanf("%d%d",&n,&k);
    // int a[n]={0};
    int a[n+10];
    // for(j=0;j<n;j++) a[j]=0; //这是初始化的一种方法。还有一种方法，使用memset()函数。来试试看。
    memset(a,0,sizeof(a));  
    for(i=1;i<=k;i++)
        for(j=0;j<n;j++) 
            if((j+1)%i==0) a[j]==1?a[j]=0:a[j]=1;
    for(j=0;j<n;j++) if(a[j]==1)printf("%d ",j+1);
    return 0;
}