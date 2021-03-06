// 8647 实现图的存储结构

// 时间限制:1000MS  内存限制:1000K
// 提交次数:1499 通过次数:1092

// 题型: 编程题   语言: G++;GCC
// Description

// 实现有向图的邻接矩阵存储结构。



// 输入格式

// 第一行：输入图的顶点个数n（各个顶点的默认编号为1~n）， 边的条数m。
// 第二 ~ m+1行：每行输入两个顶点编号i、j，表示连接顶点i到顶点j的一条边。


// 输出格式

// 分n行输出n*n的邻接矩阵，表示所输入的图存储，顶点i和顶点j之间如果有边相连，则输出1，没边相连则输出0。


// 输入样例

// 4 4
// 1 2
// 1 3
// 3 4
// 4 1


// 输出样例

// 0 1 1 0
// 0 0 0 0
// 0 0 0 1
// 1 0 0 0


// 提示



// 作者

// yqm2

#include <stdio.h>
int Graph_Store(int a[][1000],int m)
{
    int i,j,temp=m;
    while(temp--)
    {
        scanf("%d%d",&i,&j);
        a[i-1][j-1]=1;
    }
    return 0;
}


int a[1000][1000]={0};
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    Graph_Store(a,m);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
            if(j==n-1) putchar('\n');
        }
    return 0;
}