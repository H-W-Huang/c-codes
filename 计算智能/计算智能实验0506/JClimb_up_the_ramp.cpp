//J  Climb up the ramp
//*****
//可以递归实现??
//*************/
//Time Limit:1000MS  Memory Limit:65535K
//题型: 编程题   语言: 无限制
//描述
//
//The whole nation is looking forward to the coming Beijing 2008 Olympic games. The Olympic Games offers a way for man to surpass
//himself, and the essence of the Games lies in the spirit of competition and sense of honor.
//
//Huan used to be a lazy boy but now
//the Olympic spirit inspirits him.
//
//He sets up a running plan for himself, that is, keeps running around the campus every day.
//
//There’s a stepped ramp in the campus that Huan passes when running. The ramp has n(1=<n<=45) steps, and Huan can only take
//one or two steps every move.
//
//The Question is :How many kinds of possibilities are there for him to climb up the ramp?
//
//输入格式
//
//The first line of the input contains a single integer T, the number of test cases. The following T lines, each contains an integer
//n ( 1 <= n <= 45 ).
//输出格式
//
//Each case output a single line containing the amount of the total possibilities
//输入样例

//3
//1
//2
//5
//输出样例
//
//1
//2
//8


#include <stdio.h>
//
//f(n)=f(n-1)+f(n-2);
//f(1)=1;
//f(2)=2

int possibilities(int n,int a[])
{
    if(a[n]!=0) return a[n];
    if(n>2) { a[n]=(possibilities(n-2,a)+possibilities(n-1,a)); return a[n];}
//    else if(n==1) return 1;
//    else if(n==2) return 2;

}

int memory_list[100000]={0,1,2};
int main()
{
    int t=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",possibilities(n,memory_list));
    }
    return 0;
}

//
//递归+记忆搜索搞定
