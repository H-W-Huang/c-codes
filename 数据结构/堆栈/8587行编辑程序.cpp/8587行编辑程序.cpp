/*8587 �б༭����
ʱ������:1000MS  �ڴ�����:1000K
�ύ����:3976 ͨ������:1807

����: �����   ����: C++;C



Description
*/
//����ջ��д�򵥵��б༭���򣺽����û����ն�����ĳ�������ݣ�����������У������û������������ڷ�������ʱ���Լ�ʱ���������磺���û����ָոռ����һ���ַ��Ǵ��ʱ�����Բ���һ���˸����#�����Ա�ʾǰһ���ַ���Ч��������ֵ�ǰ��������ڲ��϶�����Բ��ȣ�����Լ���һ�����з���@�����Ա�ʾ��ǰ���е��ַ�����Ч�����磺������ն˽��������������ַ��� whli##ilr#e (s#*s) outcha@putchar(*s=#++); ��ʵ����Ч�����������У� while (*s) putchar(*s++); ����Ŀ�������ֺ�����Ҫ���б༭���������������������������
typedef char SElemType;
#include"malloc.h"
#include"stdio.h"
#include"math.h"
#include"stdlib.h" // exit()
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0A
typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
#define STACK_INIT_SIZE 10 // �洢�ռ��ʼ������
 #define STACKINCREMENT 2 // �洢�ռ��������
struct SqStack
{
 SElemType *base; // ��ջ����֮ǰ������֮��base��ֵΪNULL
 SElemType *top; // ջ��ָ��
 int stacksize; // ��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}; // ˳��ջ

Status InitStack(SqStack &S)       
{      
// ����һ����ջS����ջԤ�����СΪSTACK_INIT_SIZE
// �벹ȫ����
  // if(S==NULL) return ERROR;
  S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
  if(S.base==NULL) return ERROR;
  S.top=S.base;
  S.stacksize=STACK_INIT_SIZE;
  return OK; 
}



Status DestroyStack(SqStack S)
{
  S.top=S.base;
  S.base=NULL;
  S.stacksize=0;
  free(S.base);
  return OK;
}
Status Push(SqStack &S,SElemType e)   
{

  if(S.base==NULL) return ERROR;
  //����Ƿ���ջ
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
// ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
// �벹ȫ����
  if(S.base==NULL) return ERROR;
  if(S.base==S.top) return ERROR;
  e=*(S.top-1);
  S.top--;
  return OK;
}

Status ClearStack(SqStack &S)
 { // ��S��Ϊ��ջ
   S.top=S.base;
   return OK;
 }

Status GetTop(SqStack S,SElemType &e)   
{ 
// ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
// �벹ȫ����
    if(S.base==NULL) return ERROR;
    if(S.base==S.top){/*printf("Empty Stack!\n"); */return ERROR;}
    e=*(S.top-1);
    return OK;
}

int StackLength(SqStack S) 
{
  // ����ջS��Ԫ�ظ���
  // �벹ȫ����
    if(S.base==NULL) return ERROR;
    int n;
    if(S.top==S.base) return 0;
    else
    {
      for(n=0;S.top!=S.base;S.top--) n++;
      return n;
    }
} 

Status StackTraverse(SqStack S,Status(*visit)(SElemType))
 { // ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()��
   // һ��visit()ʧ�ܣ������ʧ��
   while(S.top>S.base)
     visit(*S.base++);
   printf("\n");
   return OK;
 }
Status visit(SElemType c)
 {
   printf("%c",c);
   return OK;
 }
 
 void LineEdit()
 { // �����ַ�ջs�����ն˽���һ�в��������ù��̵����������㷨3.2
   SqStack s;
   char ch,c;
   int n,i;
   InitStack(s);
   scanf("%d",&n);  //��case
   ch=getchar();
   for(i=1;i<=n;i++)
   { ch=getchar();
     while(ch!='\n')
    {
       switch(ch)
       {
         case '#':Pop(s,c);
                  break; // ����ջ�ǿ�ʱ��ջ
         case '@':ClearStack(s);
                  break; // ����sΪ��ջ
         default :Push(s,ch); // ��Ч�ַ���ջ
       }
       ch=getchar(); // ���ն˽�����һ���ַ�
     }
     StackTraverse(s,visit); // ����ջ�׵�ջ����ջ���ַ����
    ClearStack(s); // ����sΪ��ջ
    }
   DestroyStack(s);
 }
int main()
 {
     LineEdit();
     return 0;
 }



