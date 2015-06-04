#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef char SElemType; // 定义栈元素类型
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
    return OK;
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
            printf("%c ", *p);
            p--;
        }
    }
    printf("\n");
    return OK;
}

//利用栈编写表达式求值程序：输入含有“+”、“-”、“*”、“/”四则运算的表达式，
//其中负数要用（0-正数）表示，并以=结束。
//要求输出表达式的值（两运算符号的优先关系见教材表3.1）。

//比较优先级关系的函数,返回值是 > < =三种
int trans1(char c)
{
    int n1;
    switch(c)
    {
        case '+':   n1=1;break;
        case '-' :  n1=1;break;
        case '*' :  n1=3;break;
        case '/' :  n1=3;break;
        case '(' :  n1=6;break;
        case ')' :  n1=0;break;
//        case '>':
        default :break;
    }
    printf("Priority of op1 is %d \n",n1);
    return n1;
}

int trans2(char c)
{
    int n2;
//    printf("Priority of op2 is %d \n",n2);
    switch(c)
    {
        case '+':   n2=2;break;
        case '-' :  n2=2;break;
        case '*' :  n2=4;break;
        case '/' :  n2=4;break;
        case '(' :  n2=0;break;
        case ')' :  n2=7;break;
//        case '>':
        default :break;
    }
    printf("Priority of op2 is %d \n",n2);
    return n2;
}



char Percede(char op1,char op2)
{
    char relation;
    if(trans1(op1)==trans2(op2)) relation='=';
    else if(trans1(op1)>trans2(op2)) relation='>';
    else relation='<';
    return relation;
}

int Is_operator(char c)
{
    if(c=='/'||c=='*'||c=='-'||c=='+'||c=='('||c==')') return 1;
    else if(c>='0'&&c<='9') return 0;
    else return -1;
}

int Calculator(char num1,char num2,char op)
{
    int a,b,r;
    a=num1-'0';b=num2-'0';
    switch(op)
    {
        case '+': r=a+b;break;
        case '-': r=a-b;break;
        case '*': r=a*b;break;
        case '/': r=a/b;break;
    }
    return r;
}


//int main()
//{
//    char op1,op2,op3;
//    printf("I can tell which operator has a higher priority!\n");
//    printf("Give me 2 operators!!\n");
//    //op1=getchar();
////    op2=getchar();
////    putchar(op1);
////    putchar(op2);
//    op3=percede(op1,op2);
//    printf("Reasult : %c\n",op3);
//    return OK;
//}

int main()
{
    SqStack OPrand,OPcode;
    InitStack(OPrand);InitStack(OPcode);
    char c,x,num1,num2,op;
    while((c=getchar())!='=')
    {
        if(!Is_operator(c)) Push(OPrand,c);
//    printf("The numbers you enter are listed blow:\n");

//    printf("The operators you enter are listed blow:\n");
//        StackTraverse(OPrand);
        else
        printf("%c",Percede(GetTop(OPcode,x),c));
        switch(Percede(GetTop(OPcode,x),c))
        {
            case '<' :  Push(OPcode,c);break;  //输入的操作符优先级小,则进栈
            case '=' :  Pop(OPcode,x); break;
            //优先级大的情况下开始计算
            case '>' : Pop(OPrand,num1);Pop(OPrand,num2);Pop(OPcode,op); Push(OPrand,Calculator(num1,num2,op));break;
        }
        StackTraverse(OPrand);
        GetTop(OPrand,x);
        printf("%d",x-'0');
        return 0;
    }
}

说明：
1. 更改表的形式。（二维数组）






















