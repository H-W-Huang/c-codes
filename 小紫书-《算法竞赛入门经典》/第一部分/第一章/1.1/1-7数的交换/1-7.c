#include<stdio.h>
int exchange2(int a,int b){
    a=a+b;
    b=a-b;
    a=a-b;
    printf("%d��%d\n",a,b);
}


int main(){
    int a,b;
    a=10,b=2;
    printf("����ǰ��");
    printf("%d��%d\n",a,b );
    {
        int c;
        c=a;a=b;b=c;
    }
    printf("������");
    printf("%d��%d\n",a,b );

    printf("ʹ��˫��������");
    exchange2(a,b);
    return 0;   
}
