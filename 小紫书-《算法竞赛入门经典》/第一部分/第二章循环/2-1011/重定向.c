//����ʹ��define�ķ��������ʹ�ã�ʵ���л�

// #define LOCAL
#include<stdio.h>

int main()
{
    //ָ��Ҫ�����Ŀ���ļ�
    #ifdef LOCAL
    freopen("dataout.txt","w",stdout);
    freopen("datain.txt","r",stdin);
    #endif
    int i;
    for(i=0;i<=100;i++){
        printf("%d\n",i );
    }

    int a;
    scanf("%d",&a);
    printf("�������ļ�datain.txt�������ǣ�%d\n",a);
    return 0;
}