// 8590 ���е�Ӧ�á������пͻ�ƽ���ȴ�ʱ��

// ʱ������:1000MS  �ڴ�����:1000K
// �ύ����:2956 ͨ������:1424

// ����: �����   ����: C++;C
// Description

// ���еĻ����������£�
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef double QElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)

typedef struct
{
   QElemType *base; // ��ʼ���Ķ�̬����洢�ռ�
   int front; // ͷָ��,�����в���,ָ�����ͷԪ��
   int rear; // βָ��,�����в���,ָ�����βԪ�ص���һ��λ��
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
// ����һ���ն���Q���ö���Ԥ�����СΪMAXQSIZE
    Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base) exit(1);
    Q.rear=Q.front=0;
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
// ����Ԫ��eΪQ���µĶ�βԪ��
     if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
     Q.base[Q.rear]=e;
     Q.rear=(Q.rear+1)%MAXQSIZE;
     return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
// �����в���, ��ɾ��Q�Ķ�ͷԪ��, ��e������ֵ, ������OK; ���򷵻�ERROR
     if(Q.front==Q.rear) return ERROR;
     e=Q.base[Q.front];
     Q.front=(Q.front+1)%MAXQSIZE;
     return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
// �����в��գ�����e���ض�ͷԪ�أ�������OK�����򷵻�ERROR
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    return OK;
}

int QueueLength(SqQueue Q)
{
// ����Q��Ԫ�ظ���
    return Q.rear%MAXQSIZE-Q.front%MAXQSIZE;
}
// ĳ������һ���ͻ�����ҵ��վ����һ����������пͻ������ÿλ�ͻ���ҵ�����ʱ����ĳ����Χ�ڵ�ֵ����ֻ��һ�����ڣ�һλҵ����Ա��Ҫ�����ģ��ͳ����
// һ��ʱ���ڣ����пͻ���ƽ���ȴ�ʱ�䡣ģ�����ݰ��ͻ�������Ⱥ�˳�������ɼ������룬��Ӧÿλ�ͻ����������ݣ�����ʱ�̺���Ҫ����ҵ���ʱ�䡣

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