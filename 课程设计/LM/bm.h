#ifndef BM_H_INCLUDED
#define BM_H_INCLUDED
typedef int Status;
typedef Book ElemType;

//��������ڵ�
typedef struct LNode
{
    ElemType data;   //data����ΪBook����
    struct LNode *next;
}LNode,*LinkList;

//��ʼ��
Status Initial_list(LinkList &L);
Status Add_books(LinkList &L,ElemType e);
Status Load_List(LinkList L);
Status Delete_books(LinkList &L);
Status Get_book_by_key(LinkList L,char key[]);
Status Get_book_by_author(LinkList L,char a[]);
Status Get_book_by_publisher(LinkList L,char a[]);
//����ISBN���޸���Ϣ
Status Modify_books(LinkList &L);
Status Save2File(LinkList L);
Status Books_In_A_Time(LinkList L);
#endif // BM_H_INCLUDED
