#include<stdio.h>
//这样做就避免了for的使用。倒不是说for不好。只是说，
//简洁一点不是更好么？
int main(){
    int n;
    while(n--){
        /* codes */
    }
}


//针对以 0 0为结束标志的题
//这样做的好处在于，在while顺便情形判断
//注意逗号 运算符
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b),!(a==0&&b==0)){
        /* codes */
    }         
}


//接下来这一种情况针对 没有具体表明结束标志 的情况
//具体做法是以 scanf()的有无来判断
int main(){
    int a,b;    
    while(scanf("%d%d",&a,&b)>0)
    {
        /* codes */
    }   
}