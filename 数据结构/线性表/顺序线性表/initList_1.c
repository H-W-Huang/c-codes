#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 20
#define ERROR -1
#define FALSE 0
#define OK　1
#define OVERFLOW -2;


typedef int Elemtype;
typedef int Status;

typedef struct SqList{
    Elemtype *elem;
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



Sqlist L;
int main(){
    initlsit(&L);
    printf("%d\n", L.length);
    printf("Everything is awesome!!\n");
}