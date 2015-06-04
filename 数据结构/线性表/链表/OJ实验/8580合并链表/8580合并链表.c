#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1 
#define ElemType int

typedef int Status;
typedef struct LNode
{
 int data;
 struct LNode *next;
}LNode,*LinkList;


Status ListInsert_L(LinkList &L, int i, ElemType e) {  // 算法2.9
  // 在带头结点的单链线性表L的第i个元素之前插入元素e
  LinkList p,s;
  p = L;   
  int j = 0;
  while (p && j < i-1) 
  {  // 寻找第i-1个结点
    p = p->next;
    ++j;
  } 
  if (!p || j > i-1) return ERROR;      // i小于1或者大于表长
  s = (LinkList)malloc(sizeof(LNode));  // 生成新结点
  s->data = e;  s->next = p->next;      // 插入L中
  p->next = s;
  return OK;
} // LinstInsert_L

Status ListDelete_L(LinkList &L, int i, ElemType &e) {  // 算法2.10
  // 在带头结点的单链线性表L中，删除第i个元素，并由e返回其值
  LinkList p,q;
  p = L;
  int j = 0;
  while (p->next && j < i-1) {  // 寻找第i个结点，并令p指向其前趋
    p = p->next;
    ++j;
  }
  if (!(p->next) || j > i-1) return ERROR;  // 删除位置不合理
  q = p->next;
  p->next = q->next;           // 删除并释放结点
  e = q->data;
  free(q);
  return OK;
} // ListDelete_L


int CreateLink_L(LinkList &L,int n){
// 创建含有n个元素的单链表
  LinkList p,q;
  int i;
  ElemType e;
  L = (LinkList)malloc(sizeof(LNode));
  L->next = NULL;              // 先建立一个带头结点的单链表
  L->data=n;
  q = (LinkList)malloc(sizeof(LNode));
  q = L;
  for (i=0; i<n; i++) {
    scanf("%d", &e);
    p = (LinkList)malloc(sizeof(LNode));  // 生成新结点
    p->data=e;
    p->next=NULL;
    q->next=p;
    q=p;
  }
  return OK;
}

int LoadLink_L(LinkList &L){
// 单链表遍历
 LinkList p = L->next;
 if(p==NULL)printf("The List is empty!"); // 请填空
 else
 {
     while(p!=NULL)    // 请填空
     {
        printf("%d ",p->data); 
        p=p->next;    // 请填空
     }
 }
 printf("\n");
 return OK;
}

Status Merge_LinkedList(LinkList L1,LinkList L2,LinkList &L3)
{
  LinkList p1,p2,p3;
  p1=L1->next;p2=L2->next;L3=L1;p3=L3;
  while(p1!=NULL&&p2!=NULL)
  {
    if(p1->data<=p2->data)
      {
        p3->next=p1; p3=p1;
        //printf("%d\n",p1->data );printf("%d\n",p3->data );
        p1=p1->next;}
    else 
      {
        p3->next=p2; p3=p2;
        //printf("%d\n",p2->data );
        p2=p2->next;
      }
  }
  if(p1!=NULL)
    {
      //printf("%d\n", p1->data);
      p3->next=p1;
    
    }
  if(p2!=NULL)
    {
      //printf("%d\n", p2->data);
      p3->next=p2;
    
    }
  //printf("%d\n",L3->next->data );
  //LoadLink_L(L3);
  return OK;
}




int main()
{
  LinkList L1,L2,L3;
  int a,b,c;
  scanf("%d",&a);
  CreateLink_L(L1,a);
  printf("List A:");
  LoadLink_L(L1);
  scanf("%d",&b);
  CreateLink_L(L2,b);
  printf("List B:");
  LoadLink_L(L2);
  Merge_LinkedList(L1,L2,L3);
  printf("List C:");
  LoadLink_L(L3);
  return OK;
}