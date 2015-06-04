// 8606二叉树的构建及遍历操作

// 时间限制:1000MS  内存限制:1000K
// 提交次数:2653 通过次数:1597

// 题型: 编程题   语言: G++;GCC
// Description

// 构造二叉链表表示的二叉树：按先序次序输入二叉树中结点的值（一个字符），'#'字符表示空树，构造二叉链表表示的二叉树T；再输出三种遍历序列。本题只给出部分代码,请补全内容。
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
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;


//显然，树的构建是递归的
Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch; // 生成根结点
    CreateBiTree(T->lchild);  // 构造左子树
    CreateBiTree(T->rchild);  // 构造右子树
  }
  return OK;
} // CreateBiTree


Status PrintElement( ElemType e ) {  // 输出元素e的值
printf("%c", e ); 
return OK;
}// PrintElement

Status Visit(ElemType e)
{
  if(printf("%c",e)) return 1;
  else return 0;
}

Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType e) ) {
  if(T)// 首先还要看看T是否为空
  {
    Visit(T->data);
    PreOrderTraverse(T->lchild,Visit);
    PreOrderTraverse(T->rchild,Visit);
    return OK;
     // return ERROR;
  }
  else return ERROR; 
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType e) ) {
  if(T)// 首先还要看看T是否为空
  {
    printf("Now The Node is %c\n",T->data);
    PreOrderTraverse(T->lchild,Visit);
    Visit(T->data);
    PreOrderTraverse(T->rchild,Visit);
    return OK;
     // return ERROR;
  }
  else return ERROR; 
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType e) ) {
  if(T)// 首先还要看看T是否为空
  {
    PreOrderTraverse(T->lchild,Visit);
    PreOrderTraverse(T->rchild,Visit);
    Visit(T->data);
    return OK;
     // return ERROR;
  }
  else return ERROR; 
} // PostOrderTraverse

Status Put_liner()
{
  printf("\n");
  return OK;
}


int main()   //主函数
{
  BiTree T;
  CreateBiTree(T);
  PreOrderTraverse(T,Visit);Put_liner();
  InOrderTraverse(T,Visit);Put_liner();
  PostOrderTraverse(T,Visit);Put_liner();
  return 0;
}//main


//  输入样例

// AB##C##


// 输出样例

// ABC
// BAC
// BCA