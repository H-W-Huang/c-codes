#include<stdio.h>
int main()
{
    int i,j,k,n;
    char ch;
    printf("分别输入显示的字符以及n：\n");
    scanf("%c%d",&ch,&n);
    
    for(i=1;i<=n;i++)
    {
        for(j=n-i;j>0;j--) putchar(' ');
        for(k=2*i-1;k>0;k--) putchar(ch);
        putchar('\n');

    }
    for(i=n-1;i>0;i--)  //下半部分只需修改条件就可以实现
    {
        for(j=n-i;j>0;j--) putchar(' ');
        for(k=2*i-1;k>0;k--) putchar(ch);
        putchar('\n');

    }
    return 0;
}