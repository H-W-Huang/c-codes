//8606 �������Ĺ�������������
//ʱ������:1000MS  �ڴ�����:1000K
//�ύ����:2653 ͨ������:1597
//
//����: �����   ����: G++;GCC
//
//
//
//Description
//������������ʾ�Ķ��������������������������н���ֵ��һ���ַ�����
//'#'�ַ���ʾ������������������ʾ�Ķ�����T����������ֱ������С�����ֻ�������ִ���,�벹ȫ���ݡ�
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef char  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//���Һ���ָ��
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // �㷨6.4
  // �������������������н���ֵ��һ���ַ�������#���ַ���ʾ������
  // ������������ʾ�Ķ�����T��
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;// ���ɸ����
    CreateBiTree(T->lchild);  // ����������
    CreateBiTree(T->rchild);  // ����������
  }
  return OK;
} // CreateBiTree


Status PrintElement( ElemType e ) {  // ���Ԫ��e��ֵ
printf("%c", e );
return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType e) ) {
   if(T!=NULL)
   {
        Visit(T->data);
        PreOrderTraverse(T->lchild ,Visit);
        PreOrderTraverse(T->rchild ,Visit);
   }
   else return ERROR;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     if(T!=NULL)
   {

        InOrderTraverse(T->lchild ,Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild ,Visit);
        return OK;
   }
   else return ERROR;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
   if(T!=NULL)
   {
        PostOrderTraverse(T->lchild ,Visit);
        PostOrderTraverse(T->rchild ,Visit);
        Visit(T->data);
        return OK;
   }
   else return ERROR;
} // PostOrderTraverse



int main()   //������
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T,PrintElement);putchar('\n');
    InOrderTraverse(T,PrintElement);putchar('\n');
    PostOrderTraverse(T,PrintElement);putchar('\n');
    return 0;
 }//main



//ATTENTION!!!!!!!
//�����ԭ���ر�ͼ�������������е������������ʲôgui����




