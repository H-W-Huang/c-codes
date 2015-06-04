// 1139 约瑟夫环问题

// 时间限制:500MS  内存限制:65536K
// 提交次数:157 通过次数:79

// 题型: 编程题   语言: G++;GCC
// Description

// 约瑟夫(josephus)环是这样的：假设有n个小孩围坐成一个圆圈，并从1开始依次给每个小孩编上号码。老师指定从第s位小孩起从1开始报数，当数到m时，对应的小孩出列，依次重复，问最后留下的小孩是第几个小孩？例如：总共有6个小孩，围成一圈，从第一个小孩开始，每次数2个小孩，则游戏情况如下：
//     小孩序号：1，2，3，4，5，6
//     离开小孩序号依次为：2，4，6，3，1
// 最后获胜小孩序号：5



// 输入格式

// 每组输入是三个整数n，s，m。(1 <= n <= 30, 1 <= s <= n，1 <= m <= 10) ；


// 输出格式

// 对于每组输入，请输出最后留下小孩的序号。 


// 输入样例

// 6 1 2


// 输出样例

// 5


// 作者

// admin

// #include<malloc.h>
// #include<stdio.h>
// #include<stdlib.h>
// #define OK 1
// #define ERROR 0
// typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
// typedef int QElemType;

// typedef struct
// {
//    QElemType *base; // 初始化的动态分配存储空间
//    int front; // 头指针,若队列不空,指向队列头元素
//    int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
//    int pointer;
//  }SqQueue;

// Status InitQueue(SqQueue &Q,int size)
// {
// // 构造一个空队列Q，该队列预定义大小为MAXQSIZE
//     Q.base=(QElemType*)malloc(size*sizeof(QElemType));
//     if(!Q.base) exit(1);
//     Q.rear=Q.front=0;
//     return OK;
// }

// Status EnQueue(SqQueue &Q,QElemType e)
// {
// // 插入元素e为Q的新的队尾元素
//      if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
//      Q.base[Q.rear]=e;
//      Q.rear=(Q.rear+1)%MAXQSIZE;
//      return OK;
// }

// Status DeQueue(SqQueue &Q, QElemType &e)
// {
// // 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
//      if(Q.front==Q.rear) return ERROR;
//      e=Q.base[Q.front];
//      Q.front=(Q.front+1)%MAXQSIZE;
//      return OK;
// }

// Status GetHead(SqQueue Q, QElemType &e)
// {
// // 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
//     if(Q.front==Q.rear) return ERROR;
//     e=Q.base[Q.front];
//     return OK;
// }

// int QueueLength(SqQueue Q)
// {
// // 返回Q的元素个数
//     return Q.rear%MAXQSIZE-Q.front%MAXQSIZE;
// }

// int main()
// {
//     int n,m,i;
//     SqQueue Q;
//     scanf("%d%d",&n,&m);
//     InitQueue(Q,n+1);
//     for(i=n;i>=1;i--) EnQueue(Q,i);
//     n--;
//     while(n--)
//     {

//     }
//     return 0;
// }


#include <stdio.h>
int main()
{
    int n,m,s,i,j,temp1,temp2;
    // n---总人数，m---步长 s---起始位置
    scanf("%d%d%d",&n,&s,&m);
    int a[n+2];
    a[0]=1;
    for(i=1;i<=n;i++) a[i]=i;
    j=s-1;temp1=n-1;temp2=m;
    while(temp1!=0)
    {
        while(temp2!=0)
        {
            j++;
            if(j==n+1) j=1;
            if(a[j]!=0) temp2--;
        }
        a[j]=0;
        temp2=m;
        temp1--;
       
    }
    for(i=1;i<=n;i++) if(a[i]!=0) break;
    printf("%d\n", i);
    return 0;
}

//在 n+1 与 1 之间建立映射；
//起始的位置从 s-1开始


/*****
  while(temp2!=0){
            // printf("temp2==%d\n", temp2);
            if(j==n+1) j=1;
            printf("a[%d]==%d\n",j,a[j]);
            if(a[j++]!=0) temp2--;
        }
        printf("The index of the element to be deleted is %d\n",j);
        a[j]=0;
        temp2=m;
        temp1--;
******/