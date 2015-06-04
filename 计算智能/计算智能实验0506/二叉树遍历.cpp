//8606 二叉树的构建及遍历操作
//时间限制:1000MS  内存限制:1000K
//提交次数:2653 通过次数:1597
//
//题型: 编程题   语言: G++;GCC
//
//
//
//Description
//构造二叉链表表示的二叉树：按先序次序输入二叉树中结点的值（一个字符），
//'#'字符表示空树，构造二叉链表表示的二叉树T；再输出三种遍历序列。本题只给出部分代码,请补全内容。
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

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;// 生成根结点
    CreateBiTree(T->lchild);  // 构造左子树
    CreateBiTree(T->rchild);  // 构造右子树
  }
  return OK;
} // CreateBiTree


Status PrintElement( ElemType e ) {  // 输出元素e的值
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



int main()   //主函数
{
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T,PrintElement);putchar('\n');
    InOrderTraverse(T,PrintElement);putchar('\n');
    PostOrderTraverse(T,PrintElement);putchar('\n');
    return 0;
 }//main



//ATTENTION!!!!!!!
//错误的原因特别低级，在中序遍历中调用先序遍历是什么gui！？




