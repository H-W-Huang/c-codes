#ifndef BM_H_INCLUDED
#define BM_H_INCLUDED
typedef int Status;
typedef Book ElemType;

//定义链表节点
typedef struct LNode
{
    ElemType data;   //data定义为Book类型
    struct LNode *next;
}LNode,*LinkList;

//初始化
Status Initial_list(LinkList &L);
Status Add_books(LinkList &L,ElemType e);
Status Load_List(LinkList L);
Status Delete_books(LinkList &L);
Status Get_book_by_key(LinkList L,char key[]);
Status Get_book_by_author(LinkList L,char a[]);
Status Get_book_by_publisher(LinkList L,char a[]);
//根据ISBN码修改信息
Status Modify_books(LinkList &L);
Status Save2File(LinkList L);
Status Books_In_A_Time(LinkList L);
#endif // BM_H_INCLUDED
