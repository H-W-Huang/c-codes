#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // �洢�ռ��ʼ������
#define STACKINCREMENT 10 // �洢�ռ��������

typedef char SElemType; // ����ջԪ������
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��

struct SqStack
{
     SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
     SElemType *top; // ջ��ָ��
     int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)
{
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
     S.top=S.base;
     S.stacksize=STACK_INIT_SIZE;
     return OK;
}

Status Push(SqStack &S,SElemType e)
{
// ��ջS�в���Ԫ��eΪ�µ�ջ��Ԫ��
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
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
    if(S.top==S.base) return ERROR;
     e=*--S.top;
     return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}

int StackLength(SqStack S)
{
// ����ջS��Ԫ�ظ���
    int i;
    i=S.top-S.base;
    return i;
}

Status StackTraverse(SqStack S)
{
// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
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

//����ջ��д���ʽ��ֵ�������뺬�С�+������-������*������/����������ı��ʽ��
//���и���Ҫ�ã�0-��������ʾ������=������
//Ҫ��������ʽ��ֵ����������ŵ����ȹ�ϵ���̲ı�3.1����

//�Ƚ����ȼ���ϵ�ĺ���,����ֵ�� > < =����
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
            case '<' :  Push(OPcode,c);break;  //����Ĳ��������ȼ�С,���ջ
            case '=' :  Pop(OPcode,x); break;
            //���ȼ��������¿�ʼ����
            case '>' : Pop(OPrand,num1);Pop(OPrand,num2);Pop(OPcode,op); Push(OPrand,Calculator(num1,num2,op));break;
        }
        StackTraverse(OPrand);
        GetTop(OPrand,x);
        printf("%d",x-'0');
        return 0;
    }
}

˵����
1. ���ı����ʽ������ά���飩






















