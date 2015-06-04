#include<stdio.h>
#define ERROR -1
int main(){
    int n;
    scanf("%d",&n);
    if(n<100||n>1000){
        printf("请输入一个三位数！\n" );
        printf("---->Tip:\n---->所谓若某数为水仙花数，则这个数等于该数的各位的数的平方相加\n---->比如：153=1×1+5×5+3×3\n");
        return  ERROR;
    }
    else
    {
        int a,b,c;
        a=n/100;
        b=n%100/10;
        c=n%10;
        printf("%d %d %d\n",a,b,c );
        a*a+b*b+c*c==n?printf("Yes!\n"):printf("No!\n");
    }
    printf("---->Tip:\n---->所谓若某数为水仙花数，则这个数等于该数的各位的数的平方相加\n---->比如：153=1×1+5×5+3×3\n");
    return 0;
}