#include <cstdio>
int BinaryInsertSort(int a[],int n)
{
    //整个的做法就是用二分来替换顺序查找
    int low=0,high,mid,temp,i,j;
    //需要暂时存储元素
    for(i=1;i<n;i++)
    {   
        temp=a[i];
        low=0;high=i-1;
        //注意此处high的值，不是每一次都对整个数组操作.按照这样操作的话，每一次操作时，i之前的数据已经排好序了
        while(low<=high)  //注意，等号是必需的
        {
            mid=(low+high)/2;
            if(temp<a[mid]) high=mid-1;
            else low=mid+1;
        }
        //找到插入点以后，得到（low，high其实也得以确定，而且可以确定的，插入点在0到i-1之间。插入点为high）
        //定位以后，可以进行数据后移了
        //经过上述操作，得到的low和high的关系是 low=high+1
        //也就是说，目标位置为 low(or high+1)
        printf("low:%d   high:%d \n",low,high);
        for(j=i-1;j>=low;j--)
            a[j+1]=a[j];
        a[j+1]=temp;
        for(int k=0;k<n;k++)printf("%d ",a[k]); putchar('\n');
    }
    return 0;
}


int main()
{
    int a[100],n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    BinaryInsertSort(a,n);
    // for(int k=0;k<n;k++)printf("%d ",a[k]); putchar('\n');
    return 0;
}


