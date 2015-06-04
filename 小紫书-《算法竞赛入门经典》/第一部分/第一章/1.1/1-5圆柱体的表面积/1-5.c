#include<stdio.h>
#include<math.h>

//计算圆柱体的表面积
int main(){
    const double pi=acos(-1.0); //const关键字，使得pi变量不可改变
    double r,h,s1,s2,s;
    printf("请输入圆柱体底面源的半径和高:\n");
    scanf("%lf%lf",&r,&h);
    s=2*pi*r*r+2*pi*r*h;
    printf("%.3lf\n", s);
    return 0;
}