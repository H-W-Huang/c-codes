// 9495 删除线性表中所有值为x的元素

// 时间限制:1000MS  内存限制:65535K
// 提交次数:787 通过次数:526

// 题型: 编程题   语言: G++;GCC
// Description

// 已知长度为n的线性表采用顺序存储结构。写一算法，删除线性表中所有值为x的元素。



// 输入格式

// 第一行 输入表长
// 第二行 输入指定表长的整数
// 第三行 输入待删除的整数


// 输出格式

// 第一行 表中的数据
// 第二行 处理后的表中的数据


// 输入样例

// 12
// 5 3 1 4 1 9 8 9 5 7 6 2 
// 1


// 输出样例

// 5 3 1 4 1 9 8 9 5 7 6 2 
// 5 3 4 9 8 9 5 7 6 2

#include "cstdio"
#include "malloc.h"
#define OK 1;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int Insert_Node(LinkList L,int e)
{
    LinkList p,q; // p为工作指针
    p=L;
    for(p=L;p->next!=NULL;p=p->next);
    q=(LNode *)malloc(sizeof(LNode));
    q->data=e; q->next=NULL;
    p->next=q;
    return OK;
}

int LinkList_Treavase(LinkList L)
{
    if(L==NULL) return 0;
    LinkList p;
    for(p=L->next;p!=NULL;p=p->next)
        printf("%d ",p->data);
    return OK;
}

int Delete_Node(LinkList L,int key)
{
    LinkList p=L,q;
    while(p->next!=NULL)
    {
        if(p->next->data==key)
        {
            q=p->next;
            p->next=q->next;
            free(q);
        }
        else p=p->next;
    }
    return OK;
}

int main()
{
    LinkList L,p,q;
    int n,i,key,e;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        Insert_Node(L,e);
    }//得到初始链表
    LinkList_Treavase(L); putchar('\n');
    scanf("%d",&key);
    Delete_Node(L,key);
    LinkList_Treavase(L);
    return 0;
}