// 8607 实现二叉排序树的各种算法(1)

// 时间限制:1000MS  内存限制:1000K
// 提交次数:2573 通过次数:1472

// 题型: 编程题   语言: G++;GCC
// Description

// 用函数实现如下二叉排序树算法： （1） 插入新结点 （2）   前序、中序、后序遍历二叉树 （3）   中序遍历的非递归算法 （4）  层次遍历二叉树 （5） 在二叉树中查找给定关键字(函数返回值为成功1,失败0) 


// 输入格式 

// 第一行：准备建树的结点个数n 
// 第二行：输入n个整数，用空格分隔 
// 第三行：输入待查找的关键字
// 第四行：输入待查找的关键字
// 第五行：输入待插入的关键字


// 输出格式

// 第一行：二叉树的先序遍历序列
// 第二行：二叉树的中序遍历序列
// 第三行：二叉树的后序遍历序列
// 第四行：查找结果
// 第五行：查找结果
// 第六行~第八行：插入新结点后的二叉树的先、中、序遍历序列
// 第九行：插入新结点后的二叉树的中序遍历序列(非递归算法)
// 第十行：插入新结点后的二叉树的层次遍历序列


// 输入样例

// 7
// 40 20 60 18 50 56 90
// 18  
// 35  
// 30  


// 输出样例

// 40 20 18 60 50 56 90
// 18 20 40 50 56 60 90
// 18 20 56 50 90 60 40
// 1
// 0
// 40 20 18 30 60 50 56 90
// 18 20 30 40 50 56 60 90
// 18 30 20 56 50 90 60 40
// 18 20 30 40 50 56 60 90
// 40 20 60 18 30 50 90 56


#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define OK 1;
#define ERROR 0;
#define TRUE 1;
#define FALSE 0;
#define STACK_INIT_SIZE 100 
#define STACKINCREMENT 10 
using namespace std;
typedef int Status;
typedef struct TNode
{
    int data;       //数据
    TNode *lchild;    //左儿子
    TNode *rchild;    //右儿子
}TNode, *Tree;
typedef Tree SElemType;
//查找函数
//注意这里有四个参数
//T:树根的指针 key:关键字 f:未知（T的父结点） 
//p：若key存在，指向key对应的结点，否则指向查找路径上的最后一个结点

//查找函数可以通过递归来实现

/**************************定义栈*****************************************/
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

Status Is_empty(SqStack S)
{
    if(S.base==S.top) return 1;
    return 0;
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


/****************************************************************/




Status Search_Tree(Tree T,int key,Tree f,Tree &p)
{
    if(T==NULL) {p=f;return ERROR;}
    //T存在的话，就只有三中情况
    else if(T->data==key){p=T;return OK;}
    else if(T->data>key) return Search_Tree(T->lchild,key,T,p);
    else if(T->data<key) return Search_Tree(T->rchild,key,T,p);
}




Status Insert_Node(Tree &T,int elem)
{
    //插入建立在查找之上
    //注意这里f的输入，对于T而言，其f只能是NULL
    Tree p,s;
    // printf("Now searching the Tree\n");
    if(!Search_Tree(T,elem,NULL,p))
    {
        //首先为元素elem申请空间；
        //printf("Searching completes!\n");
        Tree node;
        node=(Tree)malloc(sizeof(TNode));
        //printf("Node is successfully created!\n");
        node->data=elem;
        node->lchild=NULL;node->rchild=NULL;
        //p经过Search_Tree()后已经更新了值
        // p==NULL?printf("p==NULL!\n"):printf("p!=NULL!\n");;
        if(p==NULL)  { T=node;}  //当T为空树的时候，node作为根结点，p=node也可以接受
        else 
        {
            if(p->data>elem) p->lchild=node;
            else if(p->data<elem) p->rchild=node;
        }
        return OK;
    }
    else return ERROR;
}

Status PTraverse(Tree T)
{
    if(T)
    {
        printf("%d ",T->data);
        PTraverse(T->lchild);
        PTraverse(T->rchild);
        return OK;
    }
    else 
    return OK;
}


Status ITraverse(Tree T)
{
    if(T!=NULL)
    {
        ITraverse(T->lchild);
        printf("%d ",T->data);
        ITraverse(T->rchild);
    }
    else 
    return OK;
}

Status LTraverse(Tree T)
{
    if(T!=NULL)
    {
        LTraverse(T->lchild);
        LTraverse(T->rchild);
        printf("%d ",T->data);
        return OK;
    }
    else 
    return OK;
}


Status ITraverse_without_Recursion(Tree T)
{
    SqStack S;
    Tree p;
    InitStack(S);
    Push(S,T);  //将根结点推入栈，确保进入循环
    while(!Is_empty(S))
    {
        //将最左的结点统统推入
        while(GetTop(S,p)&&p!=NULL) Push(S,p->lchild); //p变化着
        Pop(S,p);  //由于上一步才做会在最后推入一个空指针，此处删之
        if(!Is_empty(S))
        {
            Pop(S,p);
            printf("%d ",p->data);
            Push(S,p->rchild);
        }
    }
    return OK;
}

int LayerTraverse(Tree T)
{
    queue<Tree> Q;
    Tree p;
    Q.push(T);
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        if(p->lchild!=NULL) Q.push(p->lchild);
        if(p->rchild!=NULL) Q.push(p->rchild);
        printf("%d ",p->data);
    }
    return OK;
}

int main()
{
    Tree T=NULL,p;
    int n,key1,key2;
    int num;
    // printf("Input n:\n");
    scanf("%d",&n);
    while(n--)
    {
        
        // printf("Input num:\n");
        scanf("%d",&num);
        Insert_Node(T,num);
    }

    PTraverse(T);putchar('\n');
    ITraverse(T);putchar('\n');
    LTraverse(T);putchar('\n');

    scanf("%d",&key1);
    scanf("%d",&key2);
    scanf("%d",&num);
    Insert_Node(T,num);


    Search_Tree(T,key1,NULL,p);
    Search_Tree(T,key2,NULL,p);
    // printf("%d\n",T->lchild->data );
    
    if(Search_Tree(T,key1,NULL,p)) printf("%d\n", 1); else printf("%d\n", 0);
    if(Search_Tree(T,key2,NULL,p)) printf("%d\n", 1); else printf("%d\n", 0);
    PTraverse(T);putchar('\n');
    ITraverse(T);putchar('\n');
    LTraverse(T);putchar('\n');
    ITraverse_without_Recursion(T);putchar('\n');
    LayerTraverse(T);putchar('\n');
    return 0;
}
