#include<stdio.h>
int main(){
    int n;
    double price=95;
    double cost;
    printf("���빺�����:\n");
    scanf("%d",&n);
    cost=n*price;
    if(cost>=0){   //ע���ˣ���ʵ�ʳ���������������Ϊ����
        if(cost>=300) cost*=0.8;     
    }
    printf("The cost is %.1lf.\n", cost);
    return 0;
}