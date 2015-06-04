#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
typedef int QElemType;
#define MAXQSIZE 100 // �����г���(����ѭ�����У������г���Ҫ��1)

typedef struct{
    QElemType *base; //�������б���
    int rear;           //����βָ��
    int front;          //����ͷָ��
}SqQueue;


Status InitQueue(SqQueue &Q)
{
    Q.base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
    if(Q.base==NULL) return ERROR;
    Q.rear=0;
    Q.front=0;
    return OK;
}


Status Destory_SqQuene(SqQueue &Q)
{
    if(Q.base==NULL) return ERROR;
    Q.rear=0;
    Q.front=0;
    free(Q.base);
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
        if(Q.base==NULL) return ERROR;             //����Ƿ�Ϊ��Ч����
        if(((Q.rear)+1)%MAXQSIZE==Q.f) return ERROR;   //����Ƿ����,����ʹ�ÿ��Ͻ��ܵķ���,����һ��Ԫ��
        //if((Q.rear-Q.front)+1==MAXQSIZE-1) Q.rear=0;             //
        //Q.base[Q.rear++]=e;
        //�����������ȼ���
        return OK;
}
Status DeQueue(SqQueue &Q,QElemType &e)
{
    if(Q.base==NULL) return ERROR;
    e=Q.base[Q.front++];
    return OK;

}

Status GetHead(SqQueue Q, QElemType &e)
{
    if(Q.base==NULL) return ERROR;
    e=Q.base[Q.front];
    return OK;
}

int QueueLength(SqQueue Q)
{
    if(Q.base==NULL) return ERROR;
    return Q.rear-Q.front;
}

Status QueueTraverse(SqQueue Q)
{
    if(Q.base==NULL) return ERROR;
    //int i=Q.front;
    //�ڶ�ȡ֮ǰ�����˼���Ƿ�Ϊ���б�
    if(Q.rear==Q.front) printf("The Queue is Empty!");
    else
    {
        printf("The Queue is: ");
        while(Q.front!=Q.rear) printf("%d ",Q.base[Q.front++]);
        printf("\n");
    }
    return OK;
}


/*
int main()
{
    SqQueue Q;
    QElemType e;
    if(InitQueue(Q)) printf("Quene has been successfully created.\n");
    //Q.base[Q.rear]=1;
    EnQueue(Q,1);
    EnQueue(Q,2);
    QueueTraverse(Q);
    printf("%d\n",Q.base[Q.rear-1]);
    printf("Now delete a element from the queue.\n");
    DeQueue(Q,e);
    printf("Element %d has been deleted.\n", e);
    GetHead(Q,e);
    printf("The head element is %d \n",e);
    Q.rear++;
    if(Destory_SqQuene(Q)) printf("The Quene has been successfully deleted!\n");
    return OK;
}
*/

int main()
{
	int a;
  SqQueue S;
	QElemType x, e;
  if(InitQueue(S))    // �ж�˳����Ƿ񴴽��ɹ��������
	{
		printf("A Queue Has Created.\n");
	}
	while(1)
	{
	printf("1:Enter \n2:Delete \n3:Get the Front \n4:Return the Length of the Queue\n5:Load the Queue\n0:Exit\nPlease choose:\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1: scanf("%d", &x);
				  if(!EnQueue(S,x)) printf("Enter Error!\n"); // �ж�����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Entered!\n", x);
				  break;
			case 2: if(!DeQueue(S,e)) printf("Delete Error!\n"); // �жϳ����Ƿ�Ϸ��������
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(!GetHead(S,e))printf("Get Head Error!\n"); // �ж�Get Head�Ƿ�Ϸ��������
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",QueueLength(S));  //�����
				  break;
			case 5:  QueueTraverse(S);//�����
				  break;
			case 0: return 1;
		}
	}

	return 0;
}




