//主要关注的问题： 
//浮点误差！
#include<stdio.h>
#include<math.h>
//这是先生称aabb数，在检查完全平方的方法
void approach1(){
    int a,b,n;
    a=1,b=0;
    for(a=1;a<=9;a++){
        for(b=0;b<=9;b++){
            n=a*1100+b*11;
            int m=floor(sqrt(n)+0.5);
            //这里的设置有点意思。将 n 取平方后加0.5再取整}，为的是防止 sqrt得到的结果比实际结果小，考虑到这一点，
            //就干脆放大这个数，然后来四舍五入
            //举个例子，如果n=1 ,开出来的书可能会是0.9999999而不是1，对于这种情况，若不做修正，再平方后得到0不等于1
            //为此，加上0.5来抵消这种效应        
               if(m*m==n)printf("%d\n",n);
        }
    }
}

void approach2(){
    int x,n;
    for(x=1;;x++){
        n=x*x;  //love it!!
        if(n<1000) continue;
        if(n>9999) break;
        int front=n/100;
        int last=n%100;
        if(last/10==last%10 && front%10==front/10)printf("%d\n", n);
    }
    
    
}

int main(){
    approach1();
    approach2();
    return 0;
}