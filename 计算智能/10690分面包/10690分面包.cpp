// 10690分面包

// 该题有题解

// 时间限制:1000MS  内存限制:65535K
// 提交次数:90 通过次数:29

// 题型: 编程题   语言: G++;GCC
// Description

// 在大一的时候，XCC还在stu union打酱油~~~~和十三还有奶子他们去外面吃吃喝喝是常有的事。
// 大家都知道空腹喝酒是有害肚子滴，所以呢，要买一些面包来下酒。不过我们有个习惯，
// 就是所有的n个人，每个人分得的面包必须长度相等（长度相等的面包的量是一样的），
// 同时捏~给每个人分面包时，分得的小面包必须是来自同一块面包的，即不能把两个不同面包各切一部分下来凑合成一份面包来分。
// 现在一起来的有n个人，买了m个面包，求每人分得的最长面包长度。



// 输入格式

// 第一行是人数 n 和面包数目 m (3<= n <= 16 , 1 <= m <= 100)，第二行 m 个数字表示 m 个面包的长度 L ，均为整数( 1 <= L <= 1000000)


// 输出格式

// 每人分得的最长面包长度，保留2位小数


// 输入样例

// 3  3
// 3  3  3


// 输出样例

// 3.00


// 提示

// 注意题目描述


// 来源

// scau_acm 

// 作者

// scau_acm
#include <cstdio>
#include <math.h>
#include <algorithm>
using namespace std;


int check(int n,int m,double bread[],double mid)
{
    int sum=0;
    for(int i=0;i<m;i++)
    {
        sum+=(int)(bread[i]/mid);
    }
    // printf("sum==%d\n",sum);
    if(sum>=n) return 1;
    else return 0;
}



float Bread_Dispatch(int  n,int  m,double bread[],double L)
{
//    printf("Bread_Dispatching ....\n");
//    printf("L==%lf\n",L );
    double r=L,len=0,mid=0;
//    printf("r==%lf\n",r);
    while(fabs(len-r)>0.0002)  //由于判断的是浮点数的计算结果，这里使用绝对值，做差，来作为条件的组成
    {
        mid=(r+len)/2;
//         printf("mid==%lf\n",mid);
//         printf("r==%lf\n",r );
        if(check(n,m,bread,mid)) len=mid;
        else r=mid;
//         printf("len==%lf\n",len);
    }
    return len;
}



double bread[1000005];
int main()
{
    int n,m;
    double L=0.0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {scanf("%lf",&bread[i]); L+=bread[i];}
    printf("%.2f",Bread_Dispatch(n,m,bread,L));
}
