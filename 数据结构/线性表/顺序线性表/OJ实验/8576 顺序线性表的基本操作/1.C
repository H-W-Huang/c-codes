#include<stdio.h>
#include<malloc.h>
#define OK 1 
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define ElemType int

typedef struct
{
    int *elem;
    int length;
    int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem) return ERROR;
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;

}


int Load_Sq(SqList &L)
{
// 输出顺序表中的所有元素
    int i;
    if(L.length==0) printf("The List is empty!");  // 请填空
    else
    {
        printf("The List is: ");
        for(i=0;i<=L.length-1;i++) printf("%d ",L.elem[i]);  // 请填空
    }
    printf("\n");
    return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
    // if(L==NULL) return ERROR;
    if(i<0||i>L.length+1) return ERROR;
    int k;
    if(L.length==0) {L.elem[i-1]=e;L.length++;}  
    else
    {
        for(k=L.length-1;k>=i-1;k--)
        {
             L.elem[k+1]=L.elem[k];
        }
        L.elem[i-1]=e;
        L.length++;
    }
    if(L.length>=LIST_INIT_SIZE)
    {
        ElemType *newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        L.elem=newbase;
        L.listsize=LIST_INIT_SIZE+LISTINCREMENT;
    }
    

    return OK;
}

int ListDelete_Sq(SqList &L,int i, int &e)
{
    if(i<0||i>=L.length+1) return ERROR;
    int k;
    if(i==L.length) {e=L.elem[i-1];L.length--;}
    else
    {
        e=L.elem[i-1];
        for(k=i-1;k<=L.length;k++) {L.elem[k]=L.elem[k+1];}
        L.length--;
    }
    
    
    return OK;
}


int main()
{
    SqList T;
    int a, i;
    ElemType e, x;
    if(InitList_Sq(T))    // 判断顺序表是否创建成功
    {
        printf("A Sequence List Has Created.\n");
    }
    while(1)
    {
        printf("1:Insert element\n2:Delete element\n3:Load all elements\n0:Exit\nPlease choose:\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1: scanf("%d%d",&i,&x);
                    if(!ListInsert_Sq(T,i,x)) printf("Insert Error!\n"); // 判断i值是否合法，请填空
                    else printf("The Element %d is Successfully Inserted!\n", x); 
                    break;
            case 2: scanf("%d",&i);
                    if(!ListDelete_Sq(T,i,e)) printf("Delete Error!\n"); // 判断i值是否合法，请填空
                    else printf("The Element %d is Successfully Deleted!\n", e);
                    break;
            case 3: Load_Sq(T);
                    break;
            case 0: return 1;
        }
    }
}




