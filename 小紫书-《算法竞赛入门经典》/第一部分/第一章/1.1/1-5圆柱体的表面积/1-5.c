#include<stdio.h>
#include<math.h>

//����Բ����ı����
int main(){
    const double pi=acos(-1.0); //const�ؼ��֣�ʹ��pi�������ɸı�
    double r,h,s1,s2,s;
    printf("������Բ�������Դ�İ뾶�͸�:\n");
    scanf("%lf%lf",&r,&h);
    s=2*pi*r*r+2*pi*r*h;
    printf("%.3lf\n", s);
    return 0;
}