// 8649 图的广度遍历

// 时间限制:1000MS  内存限制:1000K
// 提交次数:1573 通过次数:975

// 题型: 编程题   语言: G++;GCC
// Description

// 使用图的深度遍历实现的邻接表存储结构和基本操作函数，在此基础上实现图的广度遍历算法并加以测试。注意正确使用队列存储结构。



// 输入格式

// 第一行：输入0到3之间整数(有向图:0,有向网:1,无向图:2,无向网:3)；
// 第二行：输入顶点数和边数；
// 第三行：输入各个顶点的值（字符型，长度〈3）；(遍历从输入的第一个顶点开始)
// 第四行：输入每条弧(边)弧尾和弧头(以空格作为间隔),如果是网还要输入权值；


// 输出格式

// 输出对图广度遍历的结果


// 输入样例

// 0
// 3 3
// a b c
// a b
// b c
// c b


// 输出样例

// a b c


// 提示



// 作者

// yqm

#include "string.h"
#include "malloc.h" /* malloc()等 */
#include "stdio.h" /* EOF(=^Z或F6),NULL */
#include "stdlib.h" /* exit() */
#include  <queue>
using namespace std;

typedef int InfoType; /* 顶点权值类型 */
#define MAX_NAME 3 /* 顶点字符串的最大长度+1 */
typedef char VertexType[MAX_NAME]; /* 字符串类型 */
/*图的邻接表存储表示 */
#define MAX_VERTEX_NUM 20


typedef enum{DG,DN,AG,AN}GraphKind; /* {有向图,有向网,无向图,无向网} */


//定义弧结点(结点？)类型
typedef struct ArcNode
{
    int adjvex; /* 该弧所指向的顶点的位置 */
    struct ArcNode *nextarc; /* 指向下一条弧的指针 */
    InfoType *info; /* 网的权值指针） */
}ArcNode; /* 表结点 */


//定义结点类型
typedef struct
{
    VertexType data; /* 顶点信息 */
    ArcNode *firstarc; /* 第一个表结点的地址,指向第一条依附该顶点的弧的指针 */
}VNode,AdjList[MAX_VERTEX_NUM]; /* 头结点 */



typedef struct
{
    AdjList vertices;
    int vexnum,arcnum; /* 图的当前顶点数和弧数 */
    int kind; /* 图的种类标志 */
}ALGraph;

//定位结点的位置
int LocateVex(ALGraph G,VertexType u)
{ /* 初始条件: 图G存在,u和G中顶点有相同特征 */
/* 操作结果: 若G中存在顶点u,则返回该顶点在图中位置;否则返回-1 */
    int i;
    for(i=0;i<G.vexnum;++i)
        if(strcmp(u,G.vertices[i].data)==0)
            return i;
    return -1;
}



// 此程序中，图是存放在邻接表中的
void CreateGraph(ALGraph *G)
{ /* 采用邻接表存储结构,构造没有相关信息的图G(用一个函数构造4种图) */
    int i,j,k;
    int w; /* 权值 */
    VertexType va,vb;
    ArcNode *p;
    //printf("Enter the type of map:(0~3): ");
    scanf("%d",&(*G).kind);
    //printf("Enter Vertex number,Arc number: ");
    scanf("%d%d",&(*G).vexnum,&(*G).arcnum);
    //printf("Enter %d Vertex :\n",(*G).vexnum);
    for(i=0;i<(*G).vexnum;++i) /* 构造顶点向量 */
    {
        scanf("%s",(*G).vertices[i].data);
        (*G).vertices[i].firstarc=NULL;
    }
    //if((*G).kind==1||(*G).kind==3) /* 网 */
    //  printf("Enter order every arc weight,head and tail (Takes the gap by the blank space ):\n");
    //else /* 图 */
    //  printf("Enter order every arc head and tail (Takes the gap by the blank space ):\n");
    for(k=0;k<(*G).arcnum;++k) /* 构造表结点链表 */
    {
        if((*G).kind==1||(*G).kind==3) /* 网 */
        scanf("%d%s%s",&w,va,vb);
        else /* 图 */
        scanf("%s%s",va,vb);
        i=LocateVex(*G,va); /* 弧尾 */
        j=LocateVex(*G,vb); /* 弧头 */
        p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        if((*G).kind==1||(*G).kind==3) /* 网 */
        {
            p->info=(int *)malloc(sizeof(int));
            *(p->info)=w;
        }
        else
        p->info=NULL; /* 图 */
        p->nextarc=(*G).vertices[i].firstarc; /* 插在表头 */
        (*G).vertices[i].firstarc=p;
        if((*G).kind>=2) /* 无向图或网,产生第二个表结点 */
        {
            p=(ArcNode*)malloc(sizeof(ArcNode));
            p->adjvex=i;
            if((*G).kind==3) /* 无向网 */
            {
                p->info=(int*)malloc(sizeof(int));
                *(p->info)=w;
            }
            else
            p->info=NULL; /* 无向图 */
            p->nextarc=(*G).vertices[j].firstarc; /* 插在表头 */
            (*G).vertices[j].firstarc=p;
        }
    }
}

VertexType* GetVex(ALGraph G,int v)
{ /* 初始条件: 图G存在,v是G中某个顶点的序号。操作结果: 返回v的值 */
    if(v>=G.vexnum||v<0)
        exit(0);
    return &G.vertices[v].data;
}

int FirstAdjVex(ALGraph G,VertexType v)
{ /* 初始条件: 图G存在,v是G中某个顶点 */
/* 操作结果: 返回v的第一个邻接顶点的序号。若顶点在G中没有邻接顶点,则返回-1 */
    ArcNode *p;
    int v1;
    v1=LocateVex(G,v); /* v1为顶点v在图G中的序号 */
    p=G.vertices[v1].firstarc;
    if(p)
        return p->adjvex;
    else
        return -1;
}

int NextAdjVex(ALGraph G,VertexType v,VertexType w)
{ /* 初始条件: 图G存在,v是G中某个顶点,w是v的邻接顶点 */
/* 操作结果: 返回v的(相对于w的)下一个邻接顶点的序号。 */
/* 若w是v的最后一个邻接点,则返回-1 */
    ArcNode *p;
    int v1,w1;
    v1=LocateVex(G,v); /* v1为顶点v在图G中的序号 */
    w1=LocateVex(G,w); /* w1为顶点w在图G中的序号 */
    p=G.vertices[v1].firstarc;
    while(p&&p->adjvex!=w1) /* 指针p不空且所指表结点不是w */
        p=p->nextarc;
    if(!p||!p->nextarc) /* 没找到w或w是最后一个邻接点 */
        return -1;
    else /* p->adjvex==w */
        return p->nextarc->adjvex; /* 返回v的(相对于w的)下一个邻接顶点的序号 */
}

/*深度遍历*/
int visited[MAX_VERTEX_NUM]; /* 访问标志数组(全局量),未访问标记0，访问标记1 */
void(*VisitFunc)(char* v); /* 函数变量(全局量) */
void DFS(ALGraph G,int v)
{ /* 从第v个顶点出发递归地深度优先遍历图G。算法7.5 */
/* 设置访问标志为TRUE(已访问) */
/* 访问第v个顶点 */
/* 对v的尚未访问的邻接点w递归调用DFS */
    visited[v]=1;  //将访问的元素标记已访问
    VisitFunc(G.vertices[v].data);
    int w;
    for(w=FirstAdjVex(G,G.vertices[v].data); w>=0;w=NextAdjVex(G,G.vertices[v].data,G.vertices[w].data) )
        if(!visited[w]) DFS(G,w);
}

void DFSTraverse(ALGraph G,void(*Visit)(char*))
{ /* 对图G作深度优先遍历。算法7.4 */
/* 使用全局变量VisitFunc,使DFS不必设函数指针参数 */
/* 访问标志数组初始化 */
/* 对尚未访问的顶点调用DFS */
    VisitFunc=Visit;
    int v;
    for(v=0;v<G.vexnum;v++) visited[v]=0; //先将各个元素设定为未访问；
    for(v=0;v<G.vexnum;v++)
    {
        //对于一个元素，要是未访问过，对其进行深度遍历
        if(visited[v]==0)
        {
            DFS(G,v);
        }
    }

}


void BFS(ALGraph G,void(*Visit)(char*))
{
    int v,u,w;
    char *s;
    for(v=0;v<G.vexnum;v++) 
        visited[v]=0;
    queue<int> Q;
    for(v=0;v<G.vexnum;v++)
    {
        if(visited[v]==0)
        {
            visited[v]=1;
            Visit(G.vertices[v].data);
            Q.push(v);
            while(!Q.empty())
            {
                u=Q.front();
                Q.pop();
                for(w=FirstAdjVex(G,G.vertices[u].data);w>=0;w=NextAdjVex(G,G.vertices[u].data,G.vertices[w].data))
                    if(!visited[w]){
                        visited[w]=1;Visit(G.vertices[w].data);
                        Q.push(w);
                    }

            }
        }
    }

}

void print(char *i)
{
    printf("%s ",i);
}

int main()
{
    ALGraph g;
    CreateGraph(&g);
    BFS(g,print);
    return 1;
}