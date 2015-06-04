#include<stdio.h>
int main(){
    int n;
    double price=95;
    double cost;
    printf("输入购买件数:\n");
    scanf("%d",&n);
    cost=n*price;
    if(cost>=0){   //注意了，从实际出发，开销不可能为负的
        if(cost>=300) cost*=0.8;     
    }
    printf("The cost is %.1lf.\n", cost);
    return 0;
}