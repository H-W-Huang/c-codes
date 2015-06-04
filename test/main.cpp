#include <stdio.h>
#include <malloc.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 550 // 最大队列长度(对于循环队列，最大队列长度要减1)
typedef struct
{
   QElemType *base; // 初始化的动态分配存储空间
   int fro; // 头指针,若队列不空,指向队列头元素
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(sizeof(1000));
    Q.fro=0;
    Q.rear=0;
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
    Q.base[Q.fro]=e;
    printf("Q.base[Q.front]==%d\n",Q.base[Q.fro]);
    Q.fro++;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
    e=Q.base[Q.rear];
   Q.rear=(Q.rear+1)%1000;
    return OK;
}

int reverse(SqQueue &Q,int n)
{
    int i,e;
    EnQueue(Q,n);
    for(i=n-1;i>=1;i--)
    {
        DeQueue(Q,e);
        EnQueue(Q,e);
        EnQueue(Q,i);
    }
    return OK;
}

Status load_list(SqQueue Q)
{
    int i;
   //printf("%d\n",Q.rear);
   //printf("%d\n",Q.front);
    for(i=Q.fro-1;i>=Q.rear;i--)
    {
        // printf("i==%d\n",i);
        printf("%d",Q.base[i]);
        //printf("i=%d",i);
    }
    printf("\n");
    return OK;
}

int main()
{
    SqQueue Q;
    int n;
    scanf("%d",&n);
    InitQueue(Q);
    // EnQueue(Q,5);
    // DeQueue(Q,x);
    // EnQueue(Q,x);
    // EnQueue(Q,4);
    // DeQueue(Q,x);
    // EnQueue(Q,x);
    // EnQueue(Q,3);
    // DeQueue(Q,x);
    // EnQueue(Q,x);
    // EnQueue(Q,2);
    // DeQueue(Q,x);
    // EnQueue(Q,x);
    // EnQueue(Q,1);
    reverse(Q,n);
    load_list(Q);
    return 0;
}
