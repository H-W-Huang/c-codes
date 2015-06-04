#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // ´æ´¢¿Õ¼ä³õÊ¼·ÖÅäÁ¿
#define STACKINCREMENT 10 // ´æ´¢¿Õ¼ä·ÖÅäÔöÁ¿

typedef int SElemType; // ¶¨ÒåÕ»ÔªËØÀàÐÍ
typedef int Status; // StatusÊÇº¯ÊýµÄÀàÐÍ,ÆäÖµÊÇº¯Êý½á¹û×´Ì¬´úÂë£¬ÈçOKµÈ

struct SqStack
{
     SElemType *base; // ÔÚÕ»¹¹ÔìÖ®Ç°ºÍÏú»ÙÖ®ºó£¬baseµÄÖµÎªNULL
     SElemType *top; // Õ»¶¥Ö¸Õë
     int stacksize; // µ±Ç°ÒÑ·ÖÅäµÄ´æ´¢¿Õ¼ä£¬ÒÔÔªËØÎªµ¥Î»
}; // Ë³ÐòÕ»

Status InitStack(SqStack &S)
{
// ¹¹ÔìÒ»¸ö¿ÕÕ»S£¬¸ÃÕ»Ô¤¶¨Òå´óÐ¡ÎªSTACK_INIT_SIZE
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
     if(!S.base) return ERROR;
     S.top=S.base;
     S.stacksize=STACK_INIT_SIZE;
     return OK;
}

Status Push(SqStack &S,SElemType e)
{
// ÔÚÕ»SÖÐ²åÈëÔªËØeÎªÐÂµÄÕ»¶¥ÔªËØ
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
// ÈôÕ»²»¿Õ£¬ÔòÉ¾³ýSµÄÕ»¶¥ÔªËØ£¬ÓÃe·µ»ØÆäÖµ£¬²¢·µ»ØOK£»·ñÔò·µ»ØERROR
    if(S.top==S.base) return ERROR;
     e=*--S.top;
     return OK;
}

Status GetTop(SqStack S,SElemType &e)
{
// ÈôÕ»²»¿Õ£¬ÔòÓÃe·µ»ØSµÄÕ»¶¥ÔªËØ£¬²¢·µ»ØOK£»·ñÔò·µ»ØERROR
    if(S.top==S.base) return ERROR;
    e=*(S.top-1);
    return OK;
}

int StackLength(SqStack S)
{
// ·µ»ØÕ»SµÄÔªËØ¸öÊý
    int i;
    i=S.top-S.base;
    return i;
}

Status StackTraverse(SqStack S)
{
// ´ÓÕ»¶¥µ½Õ»µ×ÒÀ´ÎÊä³öÕ»ÖÐµÄÃ¿¸öÔªËØ
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

//ÀûÓÃÕ»±àÐ´±í´ïÊ½ÇóÖµ³ÌÐò£ºÊäÈëº¬ÓÐ¡°+¡±¡¢¡°-¡±¡¢¡°*¡±¡¢¡°/¡±ËÄÔòÔËËãµÄ±í´ïÊ½£¬
//ÆäÖÐ¸ºÊýÒªÓÃ£¨0-ÕýÊý£©±íÊ¾£¬²¢ÒÔ=½áÊø¡£
//ÒªÇóÊä³ö±í´ïÊ½µÄÖµ£¨Á½ÔËËã·ûºÅµÄÓÅÏÈ¹ØÏµ¼û½Ì²Ä±í3.1£©¡£

//±È½ÏÓÅÏÈ¼¶¹ØÏµµÄº¯Êý,·µ»ØÖµÊÇ > < =ÈýÖÖ
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
        case '+':  n2=2;break;
        case '-' :  n2=3;break;
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



char percede(char op1,char op2)
{
    char relation;
    printf("%d\n",trans1(op1));
    if(trans1(op1)==trans2(op2)) relation='=';
    else if(trans1(op1)>trans2(op2)) relation='>';
    else relation='<';
    return relation;
}

int Is_opcode(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')') retrun 1;
    else retrun 0;
}

int Operate(int a,char c,int b)
{
    int r;
    switch(c)
    {
        case '+' : r=a+b; break;
        case '-' : r=a-b; break;
        case '*' : r=a*b; break;
        case '/' : r=a/b; break;
    }
}


int main()
{
    //char op1,op2,op3;
    //printf("I can tell which operator has a higher priority!\n");
    //printf("Give me 2 operators!!\n");
    //op3=percede('-','+');
    //printf("Reasult : %c\n",op3);
    //return OK;
    SqStack Opcode,Oprand;
    InitStack(Opcode);
    InitStack(Oprand);
    char c,x,op;
    int num1,num2;
    while((c=getchar())!='\n')
    {
        if(!Is_opcode(c)){Push(Oprand,c);}
        else
        {
            switch(percede(GetTop(Opcode),c))
            {
                case '<': Push(Opcode,c); break;
                case '=': Pop(Opcode,x); break;
                case '>': Pop(Opcode,op); Pop(Oprand,num1); Pop(Oprand,num2);Push(Oprand,Operate(num1,op,num2)); break;
            }   
        }
            
    }
    printf("%d\n",GetTop(Oprand));
    return 0;
}
