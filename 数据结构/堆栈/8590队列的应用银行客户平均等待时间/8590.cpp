// 8590 队列的应用——银行客户平均等待时间

// 时间限制:1000MS  内存限制:1000K
// 提交次数:2956 通过次数:1424

// 题型: 编程题   语言: C++;C
// Description

// 队列的基本操作如下：
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef double QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
   QElemType *base; // 初始化的动态分配存储空间
   int front; // 头指针,若队列不空,指向队列头元素
   int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
    Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base) exit(1);
    Q.rear=Q.front=0;
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
// 插入元素e为Q的新的队尾元素
     if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
     Q.base[Q.rear]=e;
     Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
     if(Q.front==Q.rear) return ERROR;
     e=Q.base[Q.front];
     Q.front=(Q.front+1)%MAXQSIZE;
     return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    return OK;
}

int QueueLength(SqQueue Q)
{
// 返回Q的元素个数
    return Q.rear%MAXQSIZE-Q.front%MAXQSIZE;
}
// 某银行有一个客户办理业务站，在一天内随机地有客户到达，设每位客户的业务办理时间是某个范围内的值。设只有一个窗口，一位业务人员，要求程序模拟统计在
// 一天时间内，所有客户的平均等待时间。模拟数据按客户到达的先后顺序依次由键盘输入，对应每位客户有两个数据，到达时刻和需要办理业务的时间。

double Average_time(int n)
{
    int m,i;
    m=n;
    double totaltime=0;
    double t1,t2,t3,ttemp;
    SqQueue Atime;
    SqQueue Event;
    double Avertime=0;
    double timelist[n];
    // timelist[0]=0;
    InitQueue(Atime);
    InitQueue(Event);
    while(n--)
    {
        int Arr_time,Eventtime;
        scanf("%d%d",&Arr_time,&Eventtime);
        EnQueue(Atime,Arr_time);
        EnQueue(Event,Eventtime);
    }
    DeQueue(Atime,t3);
    // printf("==%lf\n", t2);
    for(i=1;i<m;i++)
    {
        DeQueue(Event,t1);
        totaltime+=t1;
        // printf("totaltime==%lf\n", totaltime);
        DeQueue(Atime,t2);
        // printf("t2===%lf\n",t2);
        ttemp=t3+totaltime;
        if(ttemp<=t2) {Avertime+=0;totaltime+=(t2-ttemp);}
        else {Avertime=Avertime+((t3+totaltime)-t2);/*printf("%lf\n", t3+totaltime);printf("%lf\n", ttemp-t2);*/}
        // printf("Avertime==%lf\n", Avertime);
    }
    // printf("%lf\n", Avertime/m);
    return Avertime/m;
}   

int main()
{
    int n;
    scanf("%d",&n);
    printf("%.2lf\n",Average_time(n));
    return 0;
}