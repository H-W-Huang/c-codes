#include<stdio.h>
#include<string.h>
#define maxn 20
int a[maxn][maxn];                
int main()
{
    int n,i,x,y,tot;
    printf("请输入阵的阶数：\n");
    scanf("%d",&n);
    memset(a,0,sizeof(a));                                                     
    tot=a[x=0][y=n-1]=1;   //GRACEFUL
    while(tot<n*n)
    {
        while(x+1<n  && !a[x+1][y]) a[++x][y]=++tot; //在条件满足的情况下运行，++x的值等于x+1的值
        while(y-1>=0 && !a[x][y-1]) a[x][--y]=++tot;
        while(x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;
        while(y+1<n  && !a[x][y+1]) a[x][++y]=++tot;
    }
    /*
        说明:
        1.按照下--左--上--右的顺序
        2.&& 之后的语句是为之后的操作服务的。由于数组这个初始化为0，那么非0就无形中形成一条界；
        3.为什么是 x+1 y-1呢？可以从部署的角度去考虑。
    */
    for(x=0;x<n;x++){
        for(y=0;y<n;y++)
            printf("%3d",a[x][y]);
        putchar('\n');
    }
    return 0;
}