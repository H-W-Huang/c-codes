#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct{
    QElemType *base; //创建队列本体
    int rear;           //创建尾指针
    int front;          //创建头指针
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
        if(Q.base==NULL) return ERROR;             //检查是否为无效队列
        if(((Q.rear)+1)%MAXQSIZE==Q.f) return ERROR;   //检查是否溢出,这里使用课上介绍的方法,少用一个元素
        //if((Q.rear-Q.front)+1==MAXQSIZE-1) Q.rear=0;             //
        //Q.base[Q.rear++]=e;
        //上面两条语句等价于
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
    //在读取之前别忘了检查是否为空列表
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
  if(InitQueue(S))    // 判断顺序表是否创建成功，请填空
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
				  if(!EnQueue(S,x)) printf("Enter Error!\n"); // 判断入队是否合法，请填空
				  else printf("The Element %d is Successfully Entered!\n", x);
				  break;
			case 2: if(!DeQueue(S,e)) printf("Delete Error!\n"); // 判断出队是否合法，请填空
				  else printf("The Element %d is Successfully Deleted!\n", e);
				  break;
			case 3: if(!GetHead(S,e))printf("Get Head Error!\n"); // 判断Get Head是否合法，请填空
				  else printf("The Head of the Queue is %d!\n", e);
				  break;
			case 4: printf("The Length of the Queue is %d!\n",QueueLength(S));  //请填空
				  break;
			case 5:  QueueTraverse(S);//请填空
				  break;
			case 0: return 1;
		}
	}

	return 0;
}




