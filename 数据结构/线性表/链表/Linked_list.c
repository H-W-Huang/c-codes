#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LIST_INCREAMENT 5
#define ERROR -1
#define FALSE 0
#define OK 1
#define TRUE 1
#define OVERFLOW -2

typedef int Elemtype;
typedef int Status;

typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,Linklist;


 //初始化链表，生成一个带头结点的空表
Status InitList(Linklist &L)
{
    LNode *p=(LNode *)malloc(sizeof(LNode));
    if(!p) return ERROR;
    p->next=NULL;
    p->data=2;
    L=*p;
    //printf("%d\n",L.data);
    printf("Linklist created successfully!\n");
    return OK;
}

//销毁列表，将各个结点free了 *****unfinished
Status Destory_List(Linklist &L)
{
    if(&L==NULL) printf("A empty list can't \n");
    LNode *p1,*p2;
    p1=&L;
    for(p1=p1->next;p1->next!=NULL;p1=p1->next)
    {
        p2=p1->next;
        free(p1);
        p1=p2;
    }
    L.next=NULL;
    return OK;
}





//在list末尾添加一个元素
Status Append(Linklist &L,Elemtype e)
{
    LNode *p,*posi;
    for(posi=&L;posi->next!=NULL;posi=posi->next){
        //sprintf("cycle %d:%d\n",++c,p->data);
    }
    p=(LNode *)malloc(sizeof(LNode));
    if(p==NULL) return ERROR;
    p->data=e;
    p->next=NULL;
    posi->next=p;
    return OK;
}


//移除最后一位的结点，将结点返回
Status Remove(Linklist L,LNode &p)
{
    LNode *posi1,*posi2;
    posi2=&L;
    posi1=posi2->next;
    for(;posi1->next!=NULL;posi1=posi1->next,posi2=posi2->next);
        // printf("hello!\n");
    p=*posi1;
    posi2->next=NULL;
    return OK;

}

//遍历链表
Status LoadList(Linklist L)
{
    Linklist *posi;
    posi=&L;
    posi=posi->next;
    if(posi==NULL) 
    {
        printf("Empty list!\n");
        return ERROR;
    }
    printf("The list is:");
    while(posi!=NULL)
    {
        printf("%d ",posi->data);
        posi=posi->next;
    }
    printf("\n");
    return OK;
}



int main(){ 
    Linklist L;
    LNode p;
    InitList(L);
    Append(L,5);
    Append(L,4);
    Append(L,3);
    Append(L,2);
    Append(L,1);
    Remove(L,p);
    printf("The node deleted is %d\n",p.data);
    LoadList(L);
    Destory_List(L);
    LoadList(L);
    //printf("%d\n",L.next.data);
    return 0;
}

