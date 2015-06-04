typedef char SElemType;
#include"malloc.h" 
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACKINCREMENT 2 // 存储空间分配增量
struct SqStack
{
 SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
 SElemType *top; // 栈顶指针
 int stacksize; // 当前已分配的存储空间，以元素为单位
 }; // 顺序栈
Status InitStack(SqStack &S)       
{      
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
// 请补全代码
  // if(S==NULL) return ERROR;
  S.base=(SElemType *)malloc(STACKINCREMENT*sizeof(SElemType));
  if(S.base==NULL) return ERROR;
  S.top=S.base;
  S.stacksize=STACK_INIT_SIZE;
  return OK; 
}

Status Push(SqStack &S,SElemType e)   
{

  if(S.base==NULL) return ERROR;
  //检查是否满栈
  if(S.top==&S.base[S.stacksize])
  {
    S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType)); 
    if(S.base==NULL) return ERROR;
    S.stacksize+=STACKINCREMENT;
  }
  *S.top=e;
  S.top++;
  return OK;
    
}

Status Pop(SqStack &S,SElemType &e)   
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
// 请补全代码
  if(S.base==NULL) return ERROR;
  if(S.base==S.top) return ERROR;
  e=*(S.top-1);
  S.top--;
  return OK;
}

Status GetTop(SqStack S,SElemType &e)   
{ 
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
// 请补全代码
    if(S.base==NULL) return ERROR;
    if(S.base==S.top){/*printf("Empty Stack!\n"); */return ERROR;}
    e=*(S.top-1);
    return OK;
}

Status StackEmpty(SqStack S)
{
  if(S.base==NULL) return ERROR;
  if(S.top==S.base) return TRUE;
  else return FALSE;
}

int StackLength(SqStack S) 
{
  // 返回栈S的元素个数
  // 请补全代码
    if(S.base==NULL) return ERROR;
    int n;
    if(S.top==S.base) return 0;
    else
    {
      for(n=0;S.top!=S.base;S.top--) n++;
      return n;
    }
} 




void check()
 { // 对于输入的任意一个字符串，检验括号是否配对
   SqStack s;
   SElemType ch[80],*p,e;
   if(InitStack(s)) // 初始化栈成功
   {
    //printf("请输入表达式\n");
     scanf("%s",ch);
     p=ch;
     while(*p) // 没到串尾
       switch(*p)
       {
         case '(':
         case '[':Push(s,*p);p++;/*printf("The length of the stack: %d \n", StackLength(s) );*/
                  break; // 左括号入栈，且p++
         case ')':
         case ']':if(!StackEmpty(s)) // 栈不空
                  {
                    Pop(s,e); // 弹出栈顶元素
                    //printf("Top element:%c\n", e);
                    //s中储存的总是括号是左括号这类的,故e只能是'('或'['
                    //p这时只能是 *p==']'或 ")"
                    if(*p==')'&&e!='('||*p==']'&& e!='[')   //不匹配情况
                                                // 弹出的栈顶元素与*p不配对
                    {
                      printf("isn't matched pairs\n");
                      exit(ERROR);  //直接就返回失败结果了
                    }
                    //匹配的情况,p后移
                    else
                    {
                      p++;  
                      break; // 跳出switch语句
                    }
                  }
                  else // 栈空
                  {
                    //Pop(s,e); // 弹出栈顶元素
                    //printf("Top element:%c\n", e);
                    //Pop(s,e); // 弹出栈顶元素
                    //printf("Top element:%c\n", e);
                    //处理字符串不空而栈空的情况
                    printf("lack of left parenthesis\n");
                    exit(ERROR);
                  }
         default: p++; // 其它字符不处理，指针向后移
       }
     if(StackEmpty(s)) // 字符串结束时栈空
       printf("matching\n");
     else
      //处理字符串空而栈不空的情况
       printf("lack of right parenthesis\n");

   }
 }


int main()
 {
   check();
 }


