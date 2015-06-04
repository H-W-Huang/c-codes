#include<malloc.h> 
#include<stdio.h> 
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)       
{   
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
     S.top=S.base;
     S.stacksize=STACK_INIT_SIZE;
     return OK;
}

Status Push(SqStack &S,SElemType e)   
{   
// 在栈S中插入元素e为新的栈顶元素
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return ERROR;
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)   
{   
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
     e=*--S.top;
     return OK;
}

Status GetTop(SqStack S,SElemType &e)   
{    
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return e;
}

int StackLength(SqStack S) 
{   
// 返回栈S的元素个数
    int i;
    i=S.top-S.base;
    return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
    SElemType *p = (SElemType *)malloc(sizeof(SElemType)); 
    p = S.top;       
    if(S.top==S.base)printf("The Stack is Empty!");  
    else
    {
        printf("The Stack is: ");
        p--;
        while(p>=S.base)             
        {
            printf("%d ", *p);
            p--;               
        }
    }
    printf("\n");
    return OK;
}

char Precede(char c1,char c2)
{
    int i=0,j=0;
    char table[][7]=
    {
        {'>','>','<','<','<','>','>'},
        {'>','>','<','<','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'>','>','>','>','<','>','>'},
        {'<','<','<','<','<','=','0'},
        {'>','>','>','>','>','0','>'},
        {'<','<','<','<','<','0','<'},
    };
    switch(c1)
    {
        case '+':i=0;break;
        case '-':i=1;break;
        case '*':i=2;break;
        case '/':i=3;break;
        case '(':i=4;break;
        case ')':i=5;break;
        case '#':i=6;break;
    }
    switch(c2)
    {
        case '+':j=0;break;
        case '-':j=1;break;
        case '*':j=2;break;
        case '/':j=3;break;
        case '(':j=4;break;
        case ')':j=5;break;
        case '=':j=6;break;
    }
    return table[i][j];
}

int In(char &c,SqStack &OPTR,SqStack &OPND)
{
    int sum=0;
    char op_list[7]={'+','-','*','/','(',')','='};
    int i,flag=0;   //0表示非运算符
    while(flag!=1)
    {
        // printf("Now the letter is %c \n",c);
        if(c=='0')Push(OPND,0);
        for(i=0;i<=6;i++) if(c==op_list[i]) flag=1;
        if(flag==1) { break;}
        sum=sum*10+c-'0';
        // printf("sum==%d\n", sum);
        c=getchar();
    }
    if(sum!=0) Push(OPND,sum);
    return 0;
}

int Operate(int a,char op,int b)
{
    int result=0;
    switch(op)
    {
        case '+':result=b+a;break;
        case '-':result=b-a;break;
        case '*':result=b*a;break;
        case '/':result=b/a;break;
    }
    // printf("Now the result is %d\n",result );
    return result;
}

int EvaluateExpression()
{
    int a,b,temp,e;
    char op;
    char c;
    SqStack OPTR;
    SqStack OPND;
    InitStack(OPTR); Push(OPTR,'#');
    InitStack(OPND); c=getchar();
    while(c!='='||GetTop(OPTR,e)!='#')  //注意第二个条件
    {
        In(c,OPTR,OPND); 
        // StackTraverse(OPND);
            switch(Precede(GetTop(OPTR,e),c))
            {
                case '<': Push(OPTR,c); c=getchar(); break;
                case '=': Pop(OPTR,e);c=getchar(); break; //查表可知，这种情况只会出现在c为 = 时
                case '>': Pop(OPND,a);Pop(OPND,b);Pop(OPTR,temp);op=(char)temp;Push(OPND,Operate(a,op,b));break;
            }
    }
    // StackTraverse(OPND);
    return GetTop(OPND,e);
}

int main()
{
    // char c;
    // SqStack OPTR;
    // SqStack OPND;
    // InitStack(OPTR); Push(OPTR,'#');
    // InitStack(OPND); c=getchar();
    // In(c,OPTR,OPND);
    // putchar(c);
    // In(c,OPTR,OPND);
    // In(c,OPTR,OPND);
    // StackTraverse(OPND);
    printf("%d\n",EvaluateExpression());
    return 0;
}