// 计算阶乘之和，输出其后六位
//需要用到 多步取模 的方法
//数学原理：
// 要计算只包含加法、减法、乘法、的整数表达式除以正整数n的余数，可以在每步计算后对n取余，结果不变。
#include<stdio.h>
#define MOD 100000 //要活用宏定义
void approcah1(){
    int sum=0;
    int n,i,item=1;
    printf("---->请输入n值：\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        item*=i;
        sum+=item;
    }
    printf("------>其结果是：%d\n", sum%MOD);
}

void approach2(){
    int sum=0;
    int n,i,item=1;
    printf("---->请输入n值：\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        item=item*i%MOD;
        sum=sum+item%MOD;
    }
    printf("------>其结果是：%d\n", sum%MOD);
    printf("原理：要计算只包含加法、减法、乘法、的整数表达式除以正整数\n的余数，可以在每步计算后对n取余，结果不变。\n");
}

int main(){
    printf("下面是方法1，没有是使用分步求和的方法。\n");
    approcah1();
    //---->请输入n值：
    //100
    //------>其结果是：-961703
    //显然已溢出了，问题在于，越往后，sum的值越来越大，大道int型变量装不下了。
    //这样考虑，我们需要的是 结果的后六位，前面的是不需要的。若是可以在每一步的计算值那个只取其后六位，那么就没有这样的问题了
    //于是，有了方法二
    approach2();

    return 0;
}

