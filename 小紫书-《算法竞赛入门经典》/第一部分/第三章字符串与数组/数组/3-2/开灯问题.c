#include<stdio.h>
#include<string.h>
int main(){
    int n,k,i,j;
    printf("�ֱ�����Ƶ������Լ��˵�������\n");
    scanf("%d%d",&n,&k);
    // int a[n]={0};
    int a[n+10];
    // for(j=0;j<n;j++) a[j]=0; //���ǳ�ʼ����һ�ַ���������һ�ַ�����ʹ��memset()�����������Կ���
    memset(a,0,sizeof(a));  
    for(i=1;i<=k;i++)
        for(j=0;j<n;j++) 
            if((j+1)%i==0) a[j]==1?a[j]=0:a[j]=1;
    for(j=0;j<n;j++) if(a[j]==1)printf("%d ",j+1);
    return 0;
}