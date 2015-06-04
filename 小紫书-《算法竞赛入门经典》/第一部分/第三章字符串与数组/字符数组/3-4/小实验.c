#include<stdio.h>
int main()
{
    int count=0;
    printf("%d %d %d %d \n",count,count++,count++,count++ );
    //计算顺序是从右往左的！
    return 0;
}