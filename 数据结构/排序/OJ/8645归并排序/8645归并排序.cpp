// 8645归并排序（非递归算法）

// 时间限制:1000MS  内存限制:1000K
// 提交次数:2398 通过次数:1192

// 题型: 编程题   语言: G++;GCC
// Description

// 用函数实现归并排序（非递归算法），并输出每趟排序的结果



// 输入格式

// 第一行：键盘输入待排序关键的个数n
// 第二行：输入n个待排序关键字，用空格分隔数据


// 输出格式

// 每行输出每趟排序的结果，数据之间用一个空格分隔


// 输入样例

// 10
// 5 4 8 0 9 3 2 6 7 1


// 输出样例

// 4 5    0 8    3 9    2 6    1 7
// 0 4 5 8    2 3 6 9       1 7
// 0 2 3 4 5 6 8 9          1 7
//     0 1 2 3 4 5 6 7 8 9


// 提示



// 作者

// yqm


#include <cstdio>

//归并函数
int Merge(int a[],int left,int mid,int right)
{
    int i,j;
    i=left;j=mid+1;
    int temp[100]={0},k=0;//临时数组,k指示其下标
    while(i<=mid && j<=right)
    {
        if(a[i]<=a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    //将剩余的部分写入
    while(i<=mid) temp[k++]=a[i++];
    while(j<=right) temp[k++]=a[j++];
    //将temp的数据写入a数组
    // printf("temp array:\n");
    // for(int m=0;m<k;m++) printf("%d ",temp[m] );putchar('\n');
    for(i=left,k=0;i<=right;i++,k++) a[i]=temp[k];
    return 0;
}

//归并排序主体函数，需要两个参数，数组和元素个数
int Merge_Sort(int a[],int n)
{
    int i;//可以理解为步长，也可以理解归并时左右两段的长度.每次长度为原来的2倍
    int left,right,mid;
    for(i=1;i<n;i*=2)
    {
        //在某一个i的条件下，数组需要被从头扫到尾，left初始值当然为0
        left=0;
        while(left<n)
        {   
            //从距离的角度去理解可以推出left，mid和i之间的关系
            mid=left+i-1;
            right=mid+1+i-1;

            //可能的修正，防止越界
            if(mid>=n) mid=n-1;
            if(right>=n) right=n-1;
            //开始归并
            // printf("left===%d mid===%d right===%d \n",left,mid,right );
            Merge(a,left,mid,right);
            //更新left的值
            left=right+1;
        }
        for(int k=0;k<n;k++) printf("%d ",a[k]); putchar('\n');
    }
    return 0;
}


int a[1000];
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    Merge_Sort(a,n);
    return 0;
}