



/***********************
/* 不妨归纳一个模式
/* 在主体函数内
/* 1.设置好递归边界

***********************/

/*********************
    涉及的函数和变量
1.dfs函数
2.visited数组
3.is_prime函数
4.素数表
*********************/



#include <cstdio>
#include <math.h>
int a[1000]={0};
int n;
int visited[100]={0};
int prime[1000]={0};
int make_prime_table(int prime[])
{
    int i,j;
    for(i=2;i<=sqrt(100);i++)
    {
        for(j=2;j<100;j++)
        {
            // printf("i*j==%d \n", i*j);
            if(i*j>=100) break;
            prime[j*i]=1;
        }
    }
}

int is_prime(int n,int prime[])
{   
    if(prime[n]==0) return 1;
    else return 0;
}


//主体函数
int dfs(int cur)
{
    //设置递归边界
    // printf("dfsing...\n");
    // for(int i=0;i<n;i++) printf("%d ",a[i]); putchar('\n');
    if(a[0]==1 && cur==n && is_prime(a[0]+a[n-1],prime)) //顺带把首尾的数据拿来测试一下，在下面的操作就无需再操作了
    {
        for(int i=0;i<n;i++) printf("%d ",a[i]); putchar('\n');
    }
    //不成功或者没有达到尽头的情况
    else 
        for(int i=1;i<=n;i++)   //将在当前位置尝试i个数 
        { 
            // printf("i+a[cur-1]==%d\n",i+a[cur-1] );
            if(!visited[i] && is_prime(i+a[cur-1],prime) )  // 条件: i还没有尝试过；与前一个数的和为素数 （这里也就体现了回溯额度一个优点，不每一次都完全检查。后面的是否进行检查是建立在之前的检查结果是真或假上的
            {

                // 检查成功
                // 把当前cur的值设置为 i
                // 将i标记为以访问
                // 再进行下一位的检查
                a[cur]=i;
                visited[i]=1;
                // printf("cur+1==%d\n",cur);
                dfs(cur+1);
                visited[i]=0; //再一次置零，为其他情况所用 
            }
        }
    return 0;
}

int main()
{
    int cur=0;
    scanf("%d",&n);
    make_prime_table(prime);
    prime[2]=0;
    // for(int i=1;i<20;i++) printf("%d:  %d\n",i,prime[i]);
    dfs(cur);
    return 0;
}