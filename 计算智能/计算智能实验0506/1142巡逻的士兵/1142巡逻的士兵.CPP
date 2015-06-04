// 1142 巡逻的士兵

// 该题有题解

// 时间限制:1000MS  内存限制:65536K
// 提交次数:217 通过次数:58

// 题型: 编程题   语言: G++;GCC
// Description

// 有N个士兵站成一队列, 现在需要选择几个士兵派去侦察。
// 为了选择合适的士兵, 多次进行如下操作: 如果队列超过三个士兵, 那么去除掉所有站立位置为奇数的士兵, 或者是去除掉所有站立位置为偶数的士兵。直到不超过三个战士，他们将被送去侦察。现要求统计按这样的方法，总共可能有多少种不同的正好三个士兵去侦察的士兵组合方案。

// 注: 按上法得到少于三士兵的情况不统计。

// 1 <= N <= 2的32次方-1



// 输入格式

// 有多行，每行一个数字N，最后一行是0


// 输出格式

// 对每一行的数字N，输出针对N的方案数

// 直到没有数字


// 输入样例

// 10
// 4
// 0


// 输出样例

// 2
// 0



// #include <stdio.h>
// #include <string.h>
// #include <algorithm>

// int soilder(int &c,int n)
// {
//     int n1,n2;
//     if(n%2==0){n1=n/2,n2=n/2;}
//     else {n1=n/2;n2=n/2+1;}
//     if(history[n]!=-1) return history[n];
//     else 
//     {
//         if(n<=3)
//         {
//             if(n==3) {c++; return 1;}
//             else return 0;
//         }
//         history[n]=c;
//     }
// }


// int history[100000000];
// int main()
// {
//     memset(history,-1,100000000*sizeof(int));
//     int c=0,n;
//     while(scanf("%d",&n),!(n==0))
//     {
//         soilder(c,n,history);
//         printf("%d\n",c);
//         history[n]=c;
//         c=0;
//     }
//     return 0;
// }



/********************
注释:
1.递归实现，超时....
2. 使用记忆搜索??

********************/

#include <stdio.h>
#include <string.h>
#include <algorithm>

unsigned soilder(unsigned n)
{
    unsigned n1,n2;
    if(n%2==0){n1=n/2,n2=n/2;}
    else {n1=n/2;n2=n/2+1;}

    if(n<=3)
    {
        if(n==3) return 1;
        else return 0;
    }
    else  //n>3 的情况
    {
        if(n%2==0) return 2*soilder(n1);  //当n为偶数的时候，只要算一半就可以
        return soilder(n1)+soilder(n2);     
    }

}


// int history[100000000];
int main()
{
    // memset(history,-1,100000000*sizeof(int));
    unsigned c,n;
    while(scanf("%d",&n),!(n==0))
    {
        c=soilder(n);
        printf("%d\n",c);
        // history[n]=c;
        // c=0;
    }
    return 0;
}
