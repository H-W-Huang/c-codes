//��Ҫ��ע�����⣺ 
//������
#include<stdio.h>
#include<math.h>
//����������aabb�����ڼ����ȫƽ���ķ���
void approach1(){
    int a,b,n;
    a=1,b=0;
    for(a=1;a<=9;a++){
        for(b=0;b<=9;b++){
            n=a*1100+b*11;
            int m=floor(sqrt(n)+0.5);
            //����������е���˼���� n ȡƽ�����0.5��ȡ��}��Ϊ���Ƿ�ֹ sqrt�õ��Ľ����ʵ�ʽ��С�����ǵ���һ�㣬
            //�͸ɴ�Ŵ��������Ȼ������������
            //�ٸ����ӣ����n=1 ,������������ܻ���0.9999999������1�����������������������������ƽ����õ�0������1
            //Ϊ�ˣ�����0.5����������ЧӦ        
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