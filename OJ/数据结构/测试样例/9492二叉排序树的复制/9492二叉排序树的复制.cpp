// 9492 二叉排序树的复制

// 时间限制:1000MS  内存限制:65535K
// 提交次数:672 通过次数:553

// 题型: 编程题   语言: G++;GCC
// Description

// 完成二叉排序树复制功能。我们经常对文件或文件夹进行复制和粘贴操作，在这里我们完全复制一棵二叉树。首先创建一棵具有若干结点的二叉排序树Ta，对其进行前、中、后序遍历并输出。复制生成Tb，对其进行前、中、后序遍历，再分别对两个树插入若干数据后遍历。


/******

    1.说起来，建树也好，复制也好，生成一个棵树就是进行 插入操作 。
    因此，在这道题中，赋值a树叶和就是按照a树生成b树的过程。

******/


    
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


Status TreeCopy(BiTree Ta,BiTree &Tb) //树的复制
{
    if(Ta==NULL) return 0;
    int e = Ta->data;
    InsertBiTree(Tb,Ta->data);
    TreeCopy(Ta->lchild,Tb->lchild);
    TreeCopy(Ta->rchild,Tb->rchild);
    return 1;
}





int main()   //主函数
{
    BiTree  Ta=NULL,Tb=NULL;
    int i,n,e;
    scanf("%d",&n);//生成二叉排序树Ta
    for(i=0;i<n;i++){
        scanf("%d",&e);
        InsertBiTree(Ta,e);
    }
    //前、中、后序遍历二叉树
    PreOrderTraverse(Ta,PrintElement);
    printf("\n"); //getchar();
    InOrderTraverse(Ta,PrintElement);
    printf("\n"); //getchar();
    PostOrderTraverse(Ta,PrintElement);
    printf("\n"); //getchar();
    
    //printf("Start to copy:\n");
    //getchar();
    TreeCopy(Ta,Tb);//复制生成Tb 

    scanf("%d",&e);
    InsertBiTree(Tb,e);//在Tb中插入新结点

    PreOrderTraverse(Tb,PrintElement);
    printf("\n");
    InOrderTraverse(Tb,PrintElement);
    printf("\n");
    PostOrderTraverse(Tb,PrintElement);
    printf("\n");

    scanf("%d",&e);
    InsertBiTree(Ta,e);
    PreOrderTraverse(Ta,PrintElement);
    printf("\n");
    InOrderTraverse(Ta,PrintElement);
    printf("\n");
    PostOrderTraverse(Ta,PrintElement);
    printf("\n");
    

    return 0;//补充代码
 }//main



// 输入格式

// 第一行 树的结点个数
// 第二行 输入上一行指定的整数
// 第三行 输入一个整数，插入到Tb
// 第四行 输入一个整数，插入到Ta



// 输出格式

// 第一~三行输出前、中、后序遍历二叉树
// 第四~六行输出前、中、后序遍历二叉树
// 第七~九行输出前、中、后序遍历二叉树


// 输入样例

// 5
// 50 20 10 80 70
// 90
// 5


// 输出样例

// 50 20 10 80 70
// 10 20 50 70 80
// 10 20 70 80 50
// 50 20 10 80 70 90
// 10 20 50 70 80 90
// 10 20 70 90 80 50
// 50 20 10 5 80 70
// 5 10 20 50 70 80
// 5 10 20 70 80 50


// 作者

// sjjg


