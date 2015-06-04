//使用了穷举法，不喜欢，应该，绝对有更好的方法。先按住。

#include<stdio.h>
void hanxin(int a,int b,int c){
    int n;
    for(n=10;n<=100;n++)
    {
        if(n%3==a && n%5==b && n%7==c)
        {
            printf("%d\n",n);
            break;
        }

    }
    if(n>100)printf("No answer.\n");
}

int main(){
    int a,b,c;
    freopen("datain.txt","r",stdin);
    while((scanf("%d%d%d",&a,&b,&c))>0){
        hanxin(a,b,c);
    }
    return 0;
}