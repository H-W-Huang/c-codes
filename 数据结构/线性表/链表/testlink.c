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

typedef struct L_Node{
    Elemtype data;
    struct L_Node *next;
}LNode;



Status CreateList(LNode *L,int n)
{   
    LNode *p1;
    L=(LNode *)malloc(sizeof(LNode));
    L->next=NULL;
    p1=L;
    while(n--)
    {
        LNode *p2=(LNode *)malloc(sizeof(LNode));
        int e;
        scanf("%d",&e);
        p2->data=e;
        p2->next=NULL;
        p1->next=p2;
        p1=p2;
    }
    return OK;
}

int main()
{
    LNode *L;
    CreateList(L,1);
    printf("%d\n",L->data );
    return 0;
}