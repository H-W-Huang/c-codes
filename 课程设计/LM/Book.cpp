#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Book
{
    double ISBN;              //ISBN code,13位数字
    char name[20];          //name,author,publiser使用字符指针是指向同一个地址？？
    char author[20];
    char publisher[20];
    int  release_date[4]; //month-date-year
    double price;
}Book;


void make_book(Book &b)
{
//    FILE *fp;
//    fp=fopen("data.txt","rb+");
    printf("============Add Books' Information=========\n");
    printf(">>>The ISBN of the book:\n");
    scanf("%lf",&b.ISBN);
    printf(">>>The name of the book:\n"); getchar();
    gets(b.name);
    printf(">>>The author of the book:\n");
    gets(b.author);
    printf(">>>The publisher of the book:\n");
    gets(b.publisher);
    printf(">>>The release_date of the book:\n");
    printf("(Note:The pattern of your input should be: month/date/year, like: 12/21/2012)\n");
    scanf("%d/%d/%d",&b.release_date[0],&b.release_date[1],&b.release_date[2]);
    printf(">>>The price of the book:\n");
    scanf("%lf",&b.price);
    printf("=================finish=====================\n");
//    fwrite(&b,sizeof(Book),1,fp);
//    fclose(fp);
}
