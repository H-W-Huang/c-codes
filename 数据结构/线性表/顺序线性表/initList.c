#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define LIST_INCREAMENT 5
#define ERROR -1
#define FALSE 0
#define OK 1
#define TRUE 1
#define OVERFLOW -2


typedef int Elemtype;
typedef int Status;

typedef struct SqList{
    //Elemtype *elem;
    int *elem;   //这样就可以是一个数组了
    int length;
    int listsize;
}Sqlist;



Status initlsit(Sqlist *L)
{
    L->elem=(Elemtype *)malloc(LIST_INIT_SIZE*sizeof(Elemtype));
    if(!L->elem) return OVERFLOW;
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}


Status Destory_Sqlist(SqList *L)
{
    //首先是检查待删除的list是否存在
    if(!L->elem) return ERROR;
    free(L);
    return OK;
}

//将表重置为空表(将长度置为0)
Status Clearlist(Sqlist *L)
{
    if(!L->elem) return ERROR;
    L->length=0;
}


//判断list是否为空表
Status ListEmpty(Sqlist *L)
{
    if(!L->elem) return ERROR;
    if(L->length==0)return TRUE;
    return FALSE;
}

//输出list的长度
int ListLength(Sqlist L)
{
    if(!L.elem) return ERROR;
    return L.length;
}

//插入元素(重要函数！)
Status ListInsert(Sqlist *L,int i,Elemtype e)   //L为目标列表，i为插入位置，e为待插入的元素
{
    if(!L->elem) return ERROR;//检查L是否存在
    if(i<0&&i>L->length) return ERROR;
    //还需要一点就是，若屏幕
    if(L->length>=LIST_INIT_SIZE){
       Elemtype *newbase;
        newbase=(Elemtype *)realloc(L,(LIST_INIT_SIZE+LIST_INCREAMENT)*sizeof(Elemtype));
        L->elem=newbase;
        L->listsize=LIST_INIT_SIZE+LIST_INCREAMENT;
    }
    int k;
    
    if(L->length==0||i==L->length)
        L->elem[i]=e;
    else
    {
        //先把元素向后移动一位
        for(k=L->length-1;k>=i;k--) L->elem[k+1]=L->elem[k];
        L->elem[i]=e;
    }
    L->length++; //自然的，添加一个，长度加1
    return OK;
}

//删除操作
Status ListDelete(Sqlist *L,int i){
    if(!L->elem) return ERROR;//检查L是否存在
    if(i<0&&i>L->length) return ERROR;
    int k;
    if(i==L->length-1) L->length--;
    else
    {
        for(k=i;k<=L->length;k++) L->elem[k-1]=L->elem[k];
        L->length--;
    }
    return OK;
}


//遍历操作
Status Traverse(Sqlist L)
{
    int i;
    for(i=0;i<=L.length-1;i++) printf("%d \n", L.elem[i]);
}

//按编号获取元素
Status GetElem(Sqlist L,int i,Elemtype *e){
    if(!L.elem) return ERROR;//检查L是否存在
    if(i<0&&i>L.length) return ERROR;
    int k;
    for(k=0;k<=L.length-1;k++)
        if(k==i-1)
        {
            *e=L.elem[i-1];
            return OK;
        }
}

//获取目标元素的前驱
Status PriorElem(Sqlist L,int cue_e,Elemtype *pre_e){
    if(!L.elem) return ERROR;//检查L是否存在
    if(cue_e<0&&cue_e>L.length) return ERROR;
    int k;
    for(k=0;k<=L.length-1;k++)
        if(k==cue_e-1)
        {
            *pre_e=L.elem[cue_e-2];
            return OK;
        }
}

//获取目标元素的后继
Status NextElem(Sqlist L,int cue_e,Elemtype *next_e){
    if(!L.elem) return ERROR;//检查L是否存在
    if(cue_e<0&&cue_e>L.length) return ERROR;
    int k;
    for(k=0;k<=L.length-1;k++)
        if(k==cue_e-1)
        {
            *next_e=L.elem[cue_e];
            return OK;
        }
}


Status compare(int a,int b)
{

}


//通过元素值定位
Status LocateElem(SqList L,Elemtype e){
    if(!L.elem) return ERROR;//检查L是否存在
    int k;
    for(k=0;k<=L.length-1;k++)
        if(L.elem[k]==e) return k+1 ;
    if(k>=L.length) return -1;
}


//求交集,将结果并入L1中.
Status UnionList(SqList *L1,Sqlist L2)
{
    int i,e;
    printf("%d \n",&L2);
    for(i=1;i<=L2.length;i++)    //i=1,why?见Getelem函数
    {  
        //printf("The length of the list1 is %d\n",L1->length);
        //printf("The length of the list2 is %d\n",L2.length);
        GetElem(L2,i,&e);
        //printf("Now the current length of the list is %d\n", ListLength(*L1));
        printf("%d  ",e);
        if(LocateElem(*L1,e)==-1)
        {
            // printf("Here we come to Insert!\n");
            ListInsert(L1,L1->length,e);//在该函数里，插入一个，长度加1，所以不需要再增加长度
            // L1->length++;
            printf("-----Now the current length of the list is %d\n", ListLength(*L1));
        }
            
    }
}

//合并两个列表，将结果放在第三个列表里。其外，第三个列表里元素的顺序是递增的。(前提是原列表已排好序)
//思路上，还是使用打擂台的方法
Status MergetList(Sqlist L1,Sqlist L2,SqList *L3)
{
    int i=1,j=1,k=0,e1,e2;
    //将长度赋给另一个变量，有利于这个函数的实现，see:
    int L1_len=L1.length; int L2_len=L2.length;  
    // printf("%d ",L2_len);
    while((i<=L1_len) && (j<=L2_len))
    {
        //尽量使用现有的函数
        GetElem(L1,i,&e1); GetElem(L2,j,&e2);
        //printf("%d\n", e1);
        if(e1<=e2){ListInsert(L3,k++,e1);i++;}
        else {ListInsert(L3,k++,e2);j++;}

    }
    while(i<=L1_len) {GetElem(L1,i++,&e1);ListInsert(L3,k++,e1);i++;}
    while(j<=L2_len) {GetElem(L2,j,&e2);ListInsert(L3,k++,e2);j++;}
    return OK;
}


Sqlist L1;
Sqlist L2;
Sqlist L3;
int main(){
    Elemtype e; //存放函数返回值
    initlsit(&L1);//注意这样实参的形式
    initlsit(&L2);
    initlsit(&L3);
    printf("The current length of the list is %d\n", ListLength(L1));
    ListInsert(&L1,0,1);
    printf("Insert %d in 1st place.\n",L1.elem[0]);
    ListInsert(&L1,1,2);
    ListInsert(&L1,2,9);
    ListInsert(&L1,1,34);
    printf("The length of the list1 is %d",L1.length);

    ListInsert(&L2,0,5);
    ListInsert(&L2,1,12);
    ListInsert(&L2,2,24);
    ListInsert(&L2,3,31);
    ListInsert(&L2,4,54);
    printf("print list 2!\n");
    Traverse(L2);
    printf("Now the current length of the list is %d\n", ListLength(L1));
    Traverse(L1);
    printf("--------------------------------------\n");
    //printf("Now delete the first element!\n");
    //ListDelete(&L1,0);
    //putchar('\n');
    //Traverse(L1);
    
    //Traverse(L2);
    printf("--------------------------------------\n");
    printf("Time to get you out,2nd element!\n");
    GetElem(L1,2,&e);
    printf("%d\n",e);
    printf("--------------------------------------\n");
    printf("The one before the 2nd element!\n");
    PriorElem(L1,2,&e);
    printf("%d\n",e);
    printf("--------------------------------------\n");
    printf("The one after the 2nd element!\n");
    NextElem(L1,2,&e);
    printf("%d\n",e );
    printf("--------------------------------------\n");
    printf("Now locating the element whose value is 2!\n");
    printf("%d \n" ,LocateElem(L1,2));
    printf("--------------------------------------\n");
    printf("Now uniting list1 and list2!\n");
    //UnionList(&L1,L2);
    Traverse(L1);
    printf("Now the current length of the list is %d\n", ListLength(L1));
    printf("Here comes L3!\n");

    MergetList(L1,L2,&L3);
    printf("-------------l1-----------\n");
    Traverse(L1);
    printf("-------------l2----------\n");
    Traverse(L2);
    printf("-------------l3-----------\n");
    Traverse(L3);
    if(Destory_Sqlist(&L1)) printf("List is deleted successfully!\n");
    printf("Everything is awesome!!\n");
}