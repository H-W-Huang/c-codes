//可以使用define的方法来灵活使用，实现切换

// #define LOCAL
#include<stdio.h>

int main()
{
    //指定要输出的目标文件
    #ifdef LOCAL
    freopen("dataout.txt","w",stdout);
    freopen("datain.txt","r",stdin);
    #endif
    int i;
    for(i=0;i<=100;i++){
        printf("%d\n",i );
    }

    int a;
    scanf("%d",&a);
    printf("存在于文件datain.txt的数据是：%d\n",a);
    return 0;
}