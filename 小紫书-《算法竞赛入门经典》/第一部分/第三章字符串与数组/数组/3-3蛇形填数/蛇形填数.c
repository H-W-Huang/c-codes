#include<stdio.h>
#include<string.h>
#define maxn 20
int a[maxn][maxn];                
int main()
{
    int n,i,x,y,tot;
    printf("��������Ľ�����\n");
    scanf("%d",&n);
    memset(a,0,sizeof(a));                                                     
    tot=a[x=0][y=n-1]=1;   //GRACEFUL
    while(tot<n*n)
    {
        while(x+1<n  && !a[x+1][y]) a[++x][y]=++tot; //�������������������У�++x��ֵ����x+1��ֵ
        while(y-1>=0 && !a[x][y-1]) a[x][--y]=++tot;
        while(x-1>=0 && !a[x-1][y]) a[--x][y]=++tot;
        while(y+1<n  && !a[x][y+1]) a[x][++y]=++tot;
    }
    /*
        ˵��:
        1.������--��--��--�ҵ�˳��
        2.&& ֮��������Ϊ֮��Ĳ�������ġ��������������ʼ��Ϊ0����ô��0���������γ�һ���磻
        3.Ϊʲô�� x+1 y-1�أ����ԴӲ���ĽǶ�ȥ���ǡ�
    */
    for(x=0;x<n;x++){
        for(y=0;y<n;y++)
            printf("%3d",a[x][y]);
        putchar('\n');
    }
    return 0;
}