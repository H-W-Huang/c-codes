// 9494 删除单链性表中值相同的多余结点

// 时间限制:1000MS  内存限制:65535K
// 提交次数:1040 通过次数:519

// 题型: 编程题   语言: G++;GCC
// Description

// 编写一算法，删除单链性表中值相同的多余结点。即若链表中有多个结点具有相同的数据域值，只保留其中一个结点，其余结点均从链表中删去，使得最后得到的链表中的所有结点的数据域都不相同



// 输入格式

// 第一行 输入表长
// 第二行 输入上一行指定的整数


// 输出格式

// 第一行 表中的数据
// 第二行 处理后的表中的数据


// 输入样例

// 12
// 5 3 1 4 1 9 8 9 5 7 6 2


// 输出样例

// 5 3 1 4 1 9 8 9 5 7 6 2
// 5 3 1 4 9 8 7 6 2


// 作者

// sjjg


#include "cstdio"
#include "malloc.h"
#define OK 1;
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

int Binary_Search(int a[],int len,int key)
{
    int low=0,high=len,mid;
    if(len==0) return 0;
    while(low<=high)
    {       
        mid=(low+high)/2;
        if(a[mid]==key)
            return 1;
        else if(key<a[mid]) high=mid-1;
        else if(key>a[mid]) low=mid+1;
    }
    return 0;
}

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
    LinkList p;
    for(p=L->next;p!=NULL;p=p->next)
        printf("%d ",p->data);
    return OK;
}

int Delete_Node(LinkList p)
{
    LinkList q=p->next;
    p->next=q->next;
    q->next=NULL;
    free(q);
    return OK;
}

int main()
{
    LinkList L,p,q;
    int n,i,k=0,e,a[1000],b[1000],len;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&e);
        Insert_Node(L,e);
    }//得到初始链表
    LinkList_Treavase(L);
    for(p=L;p->next!=NULL;p=p->next)
    {
        for(q=L->next;q->next!=p->next;q=q->next)
        {
            if(q->data==p->data) 
            {
                // Delete_Node(p);
            }
        }
    }
    LinkList_Treavase(L);
    return 0;
}