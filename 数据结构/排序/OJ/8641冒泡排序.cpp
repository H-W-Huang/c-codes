// 8641 冒泡排序

// 时间限制:1000MS  内存限制:1000K
// 提交次数:3093 通过次数:1361

// 题型: 编程题   语言: G++;GCC
// Description

// 用函数实现冒泡排序，并输出每趟排序的结果(要求当一趟冒泡过程中不再有数据交换，则排序结束)



// 输入格式

// 第一行：键盘输入待排序关键的个数n
// 第二行：输入n个待排序关键字，用空格分隔数据


// 输出格式

// 每行输出每趟排序结果，数据之间用一个空格分隔


// 输入样例

// 10
// 5 4 8 0 9 3 2 6 7 1


// 输出样例

// 4 5 0 8 3 2 6 7 1 9
// 4 0 5 3 2 6 7 1 8 9
// 0 4 3 2 5 6 1 7 8 9
// 0 3 2 4 5 1 6 7 8 9
// 0 2 3 4 1 5 6 7 8 9
// 0 2 3 1 4 5 6 7 8 9
// 0 2 1 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9
// 8
// 1 2 3 4 8 7 6 5

// 提示



// 作者

// yqm

#include <cstdio>

int Bubble_sort(int *a,int n)
{
    // printf("BUbble strats \n\n");
    int i,j,temp,flag=0;
    for(i=n-1;i>=1;i--)
    {
        for(j=0;j<=i;j++)
            if(a[j]>=a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=1;
            }
        // printf("flag==%d\n", flag);
        if(flag==1)
        {
            for(j=0;j<n;j++) printf("%d ", a[j]); 
            putchar('\n');
        }
        flag=0;
    }
    return 0;
}   


int main()
{
    int a[30],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    Bubble_sort(a,n);
    for(i=0;i<n;i++) printf("%d ", a[i]); 
    return 0;
}