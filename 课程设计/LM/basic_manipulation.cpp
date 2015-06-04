#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#define TURE 1
#define OK 1
#define FALSE 0
#define ERROR 0

typedef Book ElemType;
typedef int Status;


//定义链表节点
typedef struct LNode
{
    ElemType data;   //data定义为Book类型
    struct LNode *next;
}LNode,*LinkList;




//初始化
Status Initial_list(LinkList &L)
{
    //创建头结点
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL) return ERROR;
    L->data.release_date[0]=-1; //用来储存书的本数；
    L->next=NULL;
    return OK;
}

//添加书籍,此时不关心其位置，方便期起见，使用头插法
Status Add_books(LinkList &L,ElemType e)
{
    LinkList p,q;
    int flag=0;
    p=(LinkList)malloc(sizeof(LNode));
    if(p==NULL) return ERROR;
    p->data=e;
    for(q=L->next;q!=NULL;q=q->next)
    {
        if(q->data.ISBN==p->data.ISBN)
            flag=1;
    }
    if(!flag)
    {
        p->next=L->next;
        L->next=p;
        L->data.release_date[0]++;
    }
    else
    {
        printf("The book is existed!\n");
    }
    return OK;
}

//根据ISBN码删除书籍
Status Delete_books(LinkList &L)
{
    LinkList p,q;

    double temp_isbn;
    printf(">>>Enter the ISBN of the book to be deleted:\n");
    scanf("%lf",&temp_isbn);
    for(p=L->next,q=L;p!=NULL;p=p->next,q=q->next)
    {
        if(p->data.ISBN==temp_isbn)
        {
            q->next=p->next;
            p=q;
            L->data.release_date[0]--;
            printf("The book has been successfully deleted!\n");
            break;
        }
    }
    return OK;
}


//保存链表至文件
Status Save2File(LinkList L)
{
    FILE *fp;
    fp=fopen("data.txt","wb+");
    LinkList p;
    for(p=L->next;p!=NULL;p=p->next)
    {
            fwrite(&(p->data),sizeof(Book),1,fp);
    }
    fclose(fp);
    return OK;
}


//根据ISBN码修改信息
Status Modify_books(LinkList &L)
{
    LinkList p;
    double temp_isbn;
    printf("Please enter the ISBN of the book.\n");
    scanf("%lf",&temp_isbn);
    for(p=L->next;p!=NULL;p=p->next)
    {
        int i;
        char temp_keys[50];
        if(p->data.ISBN==temp_isbn)  //浮点数陷阱？
        {
            printf("What information do you want to modify?\n");
//            printf("1.ISBN\n");
            printf("1.Auther\n");
            printf("2.Publisher\n");
            printf("3.Relase date\n");
            printf("4.Price\n");
            printf("0.Return \n");
            scanf("%d",&i);
            switch(i)
            {
//                case 1: scanf("%lf",&p->data.ISBN); break;
                case 1: getchar();gets(temp_keys); strcpy(p->data.author,temp_keys);break;
                case 2:getchar();  gets(temp_keys); strcpy(p->data.publisher,temp_keys);break;
                case 3: scanf("%d/%d/%d",&p->data.release_date[0],&p->data.release_date[1],&p->data.release_date[2]);break;
                case 4: scanf("%lf",&p->data.price);break;
                case 0:break;
                default:break;
            }
            break; //由于ISBN是唯一，一旦发现就不会出现第二本，于是break；
        }
    }
    if(p==NULL) printf("Book not found!\n");
    return OK;
}

Status  date_compare(int d1[],int d2[],int d3[])
{
    if(d2[2]>d1[2]&&d2[2]<d3[2])
        return OK;
    else if((d2[2]==d1[2])&&(d2[2]==d3[2]))
    {
        if(d2[0]>d1[0]&&d2[0]<d3[0])
            return OK;
        else if(d2[0]==d1[0]&&d2[0]==d3[0])
            if(d2[1]>=d1[1]&&d2[1]<=d3[1])
                return OK;
    }
    return 0;
}


//统计函数
Status Books_In_A_Time(LinkList L)
{
    LinkList p;
    int i=0,n=0;
    struct publish
    {
        char p_name[25];
        int amount=0;
    }bgroup[10000];
    int num=0,d1[5],d3[5];
    printf(">>>Input the date to start and the date to stop:\n(Note: month should be first entered,then date,then year)\n");
    printf(">>>The date to start\n");
    scanf("%d%d%d",&d1[0],&d1[1],&d1[2]);
    printf(">>>The date to stop\n");
    scanf("%d%d%d",&d3[0],&d3[1],&d3[2]);
    printf("*******Here are the dates you have input*********\n");
    printf("month     date        year \n");
    printf("%d          %d           %d     \n",d1[0],d1[1],d1[2]);
    printf("%d          %d           %d     \n",d3[0],d3[1],d3[2]);
    for(p=L->next;p!=NULL;p=p->next)
    {
        //printf("%d          %d           %d     \n",p->data.release_date[0],p->data.release_date[1],p->data.release_date[2]);
        if(date_compare(d1,p->data.release_date,d3))
           {
                for(i=0;i<n;i++)
                {
                    if(strcmp(p->data.publisher,bgroup[i].p_name)==0)
                    {
                        bgroup[i].amount++;
                    }
                }
                if(i>=n)
                {
                     strcpy(bgroup[i].p_name,p->data.publisher);
                     bgroup[i].amount++;
                     n++;
                }
               num++;
           }
    }
    printf("There are %d books published in the time.\n",num);
    printf("Morr detail are provided below;\n");
    for(i=0;i<n;i++)
    {
        printf("Publisher :");
        puts(bgroup[i].p_name);
        printf("Amount :  %d\n",bgroup[i].amount);
    }

    return OK;
}



/*********查找操作*********************************************/

//遍历整个链表
Status Load_List(LinkList L)
{
    LinkList p;
    int i=1;
    printf("***************Book's Information*****************\n");
    for(p=L->next;p!=NULL;p=p->next)
    {
        printf("========NO. %d===========\n",i++);
        printf("Name: %s \n",p->data.name);
        printf("Author: %s \n",p->data.author);
        printf("ISBN: %.0lf \n",p->data.ISBN);
        printf("Publisher: %s \n",p->data.publisher);
        printf("Release date: %d/%d/%d \n",p->data.release_date[0],p->data.release_date[1],p->data.release_date[2]);
        printf("Price: $%.2lf\n",p->data.price);

    }
    printf("***************************************************\n");
    return OK;
}

//根据书名查找书籍
Status Get_book_by_key(LinkList L,char key[])
{
    LinkList p=L->next;
    int flag=0;
    for(p=L->next;p!=NULL;p=p->next)
    {
        if(strstr(p->data.name,key) !=NULL)
        {
            printf("========Book's Information===========\n");
            printf("Name: %s \n",p->data.name);
            printf("Author: %s \n",p->data.author);
            printf("ISBN: %.0lf \n",p->data.ISBN);
            printf("Publisher: %s \n",p->data.publisher);
            printf("Release date: %d/%d/%d \n",p->data.release_date[0],p->data.release_date[1],p->data.release_date[2]);
            printf("Price: $%.2lf\n",p->data.price);
            printf("====================================\n");
            flag=1;
        }
    }
    if(!flag) printf("Not found!");
    return OK;
}

//根据作者查找书籍
Status Get_book_by_author(LinkList L,char a[])
{
    LinkList p=L->next;
    int flag=0;
    for(p=L->next;p!=NULL;p=p->next)
    {
        if(strcmp(p->data.author,a)==0)
        {
            printf("========Book's Information===========\n");
            printf("Name: %s \n",p->data.name);
            printf("Author: %s \n",p->data.author);
            printf("ISBN: %.0lf \n",p->data.ISBN);
            printf("Publisher: %s \n",p->data.publisher);
            printf("Release date: %d/%d/%d \n",p->data.release_date[0],p->data.release_date[1],p->data.release_date[2]);
            printf("Price: $%.2lf\n",p->data.price);
            printf("====================================\n");
            flag=1;
        }
    }
    if(!flag) printf("Not found!");
    return OK;
}

//根据出版商查找书籍
Status Get_book_by_publisher(LinkList L,char a[])
{
    LinkList p=L->next;
    int flag=0;
    for(p=L->next;p!=NULL;p=p->next)
    {
        if(strcmp(p->data.publisher,a)==0)
        {
            printf("========Book's Information===========\n");
            printf("Name: %s \n",p->data.name);
            printf("Author: %s \n",p->data.author);
            printf("ISBN: %.0lf \n",p->data.ISBN);
            printf("Publisher: %s \n",p->data.publisher);
            printf("Release date: %d/%d/%d \n",p->data.release_date[0],p->data.release_date[1],p->data.release_date[2]);
            printf("Price: $%.2lf\n",p->data.price);
            printf("====================================\n");
            flag=1;
        }
    }
    if(!flag) printf("Not found!");
    return OK;
}

/**************************************************************/


int loading(LinkList &L)
{
    FILE *fp;
    fp=fopen("data.txt","ab+");
    Book b;
//    int c=0;
    if(fp==NULL)
    {
        printf("File open failed!]\n");
        return 0;
    }
    while(!feof(fp))
    {
        fread(&b,sizeof(Book),1,fp);
        Add_books(L,b);
    }
    fclose(fp);
    L->next=L->next->next;  //修正
    printf("List loaded successfully!\n");
    return 0;
}



