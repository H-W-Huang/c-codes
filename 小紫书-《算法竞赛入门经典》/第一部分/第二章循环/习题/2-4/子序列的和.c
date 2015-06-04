//首次写出现问题，int类型太小，怒能存放 65536的平方 （或类似数量级））的数
//解决方法也简单粗暴：修改类型为 double


#include<stdio.h>

void subsequece(double n,double m)
{
    double item,sum=0;
    for(;n<=m;n++)
    {
        item=1.0/(n*n);
        sum+=item;
        // printf("%lf\n", item);
        // printf("%d\n", n);

    }   
    printf("%.5lf\n", sum );
}


int main()
{
    freopen("datain.txt","r",stdin);
    double n,m;
    while(scanf("%lf%lf",&n,&m),(n!=0&&m!=0))
    {
        subsequece(n,m);
    }
    return 0;
}