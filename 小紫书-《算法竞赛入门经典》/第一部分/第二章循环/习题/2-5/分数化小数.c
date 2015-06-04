//春在问it：只要a,b,v中出现0，则会退出。条件设置出错了？

#include<stdio.h>
int de(int a,int b,int c)
{
    double n;
    n=1.0*a/b;
    if(b==0) {printf("Divider can not be 0!");return -1;}
    else printf("%.*lf\n",c,n);;
}



int main(){
    freopen("datain.txt","r",stdin);
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c))
    {
        if(a==0&&b==0&&c==0)break;
         de(a,b,c);
    }
    return 0;
}