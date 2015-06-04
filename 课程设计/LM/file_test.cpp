//#include <iostream>
#include "stdio.h"
#include "menu.h"
#include "book.h"
#include "bm.h"
#define TURE 1
#define OK 1
#define FALSE 0
#define ERROR 0

int loading(LinkList &L,FILE *fp)
{
    Book b;
    if(fp==NULL)
    {
        printf("File open failed!]\n");
        return 0;
    }
    while(!feof(fp))
    {
        fscanf(fp,"%lf",&b.ISBN);
        printf("%lf",b.ISBN);
        fgets(b.name,20,fp);
        puts(b.name);
        fgets(b.author,20,fp);
        puts(b.author);
        fgets(b.publisher,20,fp);
        puts(b.publisher);
        fscanf(fp,"%d/%d/%d",&b.release_date[0],&b.release_date[1],&b.release_date[2]);
        printf("%d/%d/%d\n", b.release_date[0],b.release_date[1],b.release_date[2]);
        fscanf(fp,"%lf",&b.price);

        printf("%lf",b.price);
        
    }
    fclose(fp);
    printf("List loaded successfully!\n");
    return 0;
}


int main()
{
    LinkList L;
    FILE *fp;
    fp=fopen("data.txt","at+");
    loading(L,fp);
    return 0;
}