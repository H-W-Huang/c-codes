// 8644 堆排序

// 时间限制:1000MS  内存限制:1000K
// 提交次数:1909 通过次数:1257

// 题型: 编程题   语言: G++;GCC
// Description

// 用函数实现堆排序，并输出每趟排序的结果



// 输入格式

// 第一行：键盘输入待排序关键的个数n
// 第二行：输入n个待排序关键字，用空格分隔数据


// 输出格式

// 第一行：初始建堆后的结果
// 其后各行输出交换堆顶元素并调整堆的结果，数据之间用一个空格分隔


// 输入样例

// 10
// 5 4 8 0 9 3 2 6 7 1


// 输出样例

// 9 7 8 6 4 3 2 5 0 1
// 8 7 3 6 4 1 2 5 0 9
// 7 6 3 5 4 1 2 0 8 9
// 6 5 3 0 4 1 2 7 8 9
// 5 4 3 0 2 1 6 7 8 9
// 4 2 3 0 1 5 6 7 8 9
// 3 2 1 0 4 5 6 7 8 9
// 2 0 1 3 4 5 6 7 8 9
// 1 0 2 3 4 5 6 7 8 9
// 0 1 2 3 4 5 6 7 8 9


// 提示



// 作者

// yqm

//堆调整---对 s 到 m 的序列进行堆排序
//使用堆排序时，0号元素不要用。否则不能正确的到其左右孩子。
#include <cstdio>


int Heap_Adjust(int a[],int s,int m)
{
    int j,temp;
    // 2*s 为 s的左孩子
    temp=a[s]; //暂时将a[s]的值存到 temp里
    printf("temp===%d\n",temp );
    printf("HeapAdjusting...\n");
    for(j=2*s;j<=m;j*=2)
    {
        if(j<m && a[j] < a[j+1]) j++;  //将j定位到最大的孩子上;    
        if(temp>=a[j]){for(int i=1;i<=10;i++) printf("%d ",a[i] );putchar('\n');  break; } //每一次比较的是a[j] 和 原树根，即temp的值                                  
        a[s]=a[j];        //将大的孩子的值赋到其双亲上
        s=j;
        for(int i=1;i<=10;i++) printf("%d ",a[i] );putchar('\n'); 
    }
    a[s]=temp;
    putchar('\n'); putchar('\n'); putchar('\n'); 

    printf("result:\n");
    for(int i=1;i<=10;i++) printf("%d ",a[i] );putchar('\n'); 
         printf("******************************************\n");
}

int Heap_sort(int a[],int n)
{
    int i,temp;
    for(i=n/2;i>0;i--)  //对非树叶的结点进行调整
        Heap_Adjust(a,i,n);
    for(i=n;i>1;i--)  //调整的顺序是自下而上的
        {temp=a[i]; a[i]=a[1]; a[1]=temp; Heap_Adjust(a,1,i-1);for(int i=1;i<=n;i++) printf("%d ",a[i] );putchar('\n'); }            
        //第一个元素与第i个元素调换位置
        //由之前建立的大顶堆，第一个元素一定是整个数组中最大的一个元素，将其放到最后，对1 ~ i-1 建立调整，从而得到次大的，之后又被房贷最后。如此反复，可得增序的序列
    return 0;
}


int main()
{
    int a[10000],n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    Heap_sort(a,n);
    return 0;
}
