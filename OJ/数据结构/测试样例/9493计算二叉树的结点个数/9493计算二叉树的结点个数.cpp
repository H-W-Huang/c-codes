// 9493 计算二叉树的结点个数

// 时间限制:1000MS  内存限制:65535K
// 提交次数:658 通过次数:513

// 题型: 编程题   语言: G++;GCC
// Description

// 构建一个二叉排序树，插入若干数据后，给出树中结点的个数。
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef int  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status InsertBiTree(BiTree &T,int e) //插入新结点
{
    if(T==NULL){
        T=(BiTNode *)malloc(sizeof(BiTNode));
        T->data=e;T->lchild=NULL;
        T->rchild=NULL;
        return 1;
    }
    if(T->data<e)
        InsertBiTree(T->rchild,e);
    else
        InsertBiTree(T->lchild,e);
    return 0;
}



Status PrintElement( ElemType e ) {  // 输出元素e的值
    printf("%d ", e );
    return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )//前序遍历二叉树
 {
    if(T==NULL)  return 0;
    Visit( T->data );
    PreOrderTraverse(T->lchild,Visit);
    PreOrderTraverse(T->rchild,Visit);
    return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) //中序遍历二叉树
{
    if(T==NULL)  return 0;
    InOrderTraverse(T->lchild,Visit);
    Visit(T->data);
    InOrderTraverse(T->rchild,Visit);
    return 1;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) )//后序遍历二叉树
 {
    if(T==NULL)  return 0;
    PostOrderTraverse(T->lchild,Visit);
    PostOrderTraverse(T->rchild,Visit);
    Visit(T->data);
    return 1;

} // PostOrderTraverse


int TreeCount( BiTree T)//树的结点数
{
    //补充内容
    if(T==NULL) return 0;
    int num=0;
    num=TreeCount(T->lchild)+TreeCount(T->rchild);
    return num+1;  //Attention！注意要加1.否则不能得到正确结构
}





int main()   //主函数
{
    BiTree  T=NULL;
    int i,n,e;
    //生成二叉排序树T
    scanf("%d",&i);
    while(i!=-1)
    {
        e=i;
        InsertBiTree(T,e);
        scanf("%d",&i);
    }
    //前、中、后序遍历二叉树
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    
         //计数并输出
    printf("%d\n", TreeCount(T));
        

    return 0;//补充代码
 }//main



// 输入格式

// 第一行 输入一组若干个整数用空格分隔，最后输入-1表示结束(-1不作为二叉排序树中的结点)


// 输出格式

// 第一~三行 前、中、后序遍历
// 第四行  树的结点个数


// 输入样例

// 50 20 10 80 70 -1


// 输出样例

// 50 20 10 80 70
// 10 20 50 70 80
// 10 20 70 80 50
// 5


// 作者

// sjjg