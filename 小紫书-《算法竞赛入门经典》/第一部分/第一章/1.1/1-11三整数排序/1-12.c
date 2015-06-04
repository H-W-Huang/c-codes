#include<stdio.h>


int main(){
    int a,b,c;
    int temp;
    scanf("%d%d%d",&a,&b,&c);
    if(a>=b){temp=a;a=b;b=temp;}
    if(b>=c){temp=b;b=c;c=temp;}
    if(a>=b){temp=a;a=b;b=temp;}

    // 教程的顺序是 ab ac bc
    printf("%d %d %d\n",a,b,c);
    return 0;
}

