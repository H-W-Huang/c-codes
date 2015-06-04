// 8640 希尔(shell)排序

// 时间限制:1000MS  内存限制:1000K
// 提交次数:1858 通过次数:1304

// 题型: 编程题   语言: G++;GCC
// Description

// 用函数实现希尔(shell)排序，并输出每趟排序的结果,初始增量d=n/2,其后d=d/2



// 输入格式

// 第一行：键盘输入待排序关键的个数n
// 第二行：输入n个待排序关键字，用空格分隔数据


// 输出格式

// 每行输出一趟排序结果，数据之间用一个空格分隔


// 输入样例

// 10
// 5 4 8 0 9 3 2 6 7 1


// 输出样例

// 3 2 6 0 1 5 4 8 7 9
// 1 0 3 2 4 5 6 8 7 9
// 0 1 2 3 4 5 6 7 8 9


// 提示



// 作者

// yqm



#include <cstdio>

int Shell_Sort(int *a,int n,int len)
{
    //0号依旧不放元素
    int i,j,dk=n/2;
    // printf("dk==%d\n",dk );
    if(dk==0) return 0;
    for(i=dk+1;i<=len;i++)
    {
        if(a[i]<a[i-dk])
        {
            a[0]=a[i];
            //出错，问题出现在这个条件的设置上: 1. j必须大于0 ； 2， 每一次比较都是与a[0]比较
            // for(j=i-dk;j>=dk;j-=dk) a[j+dk]=a[j];
            //3. i要跑到len啊...
            for(j=i-dk;j>0 && a[0]<a[j];j-=dk)  a[j+dk]=a[j];
            a[j+dk]=a[0];
        }
    }
    for(i=1;i<=len;i++) printf("%d ",a[i]); putchar('\n');
    return 0;
}

int main()
{
    int a[30],n,i;
    scanf("%d",&n);
    int len=n;
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    while(n)
    {
        // printf("n==%d\n",n );
        Shell_Sort(a,n,len);
        n=n/2;
    }
    // for(i=1;i<=len;i++) printf("%d ",a[i]); putchar('\n');

    return 0;
}