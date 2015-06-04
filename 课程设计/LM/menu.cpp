#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "book.h"
#include "bm.h"


int  menu1(LinkList L,Book b)
{

  system("cls");  ///用来清屏的，删除回车前的输入
    while(1)
    {

        printf("=============Add/Modify/Delete books==========\n");
        printf("==1.Add books\n");
        printf("--2.Modify books\n");
        printf("--3.Delete books\n");
        printf("--0.Return \n");
        printf("==============================================\n");
        int i;
        scanf("%d",&i);
        switch(i)
        {
            case 1:printf("Adding books.......\n");make_book(b);Add_books(L,b);/*Load_List(L);*/break;
            case 2:printf("Modify......\n");Modify_books(L); break;
            case 3:printf("Deleting......\n");Delete_books(L); break;
            case 0:return 0;;
        }
    }
    return 0;
}



int menu2(LinkList L)
{
    FILE *fp;
    fp=fopen("data.txt","ab+");
    system("cls");  ///用来清屏的，删除回车前的输入
    while(1)
    {

        printf("===============Search for books==============\n");
        printf("--1.List all books\n");
        printf("--2.List books by name\n");
        printf("--3.List books by publisher\n");
        printf("--4.List books by writer\n");
        printf("--0.Exit\n");
        printf("=============================================\n");
        int i;
        scanf("%d",&i);
        switch(i)
        {
            char key[50];

            case 1: printf("All the book are listed here:\n"); Load_List(L); break;
            case 2:
                        printf("Input the key word,please.");
                        scanf("%s",key);
                        Get_book_by_key(L,key);
                        break;
            case 3:
                        scanf("%s",key); //存储出版商

                        Get_book_by_publisher(L,key);
                        break;
            case 4:
                        scanf("%s",key); //存储作者
                        Get_book_by_author(L,key);
                        break;
            case 0:return 0;;
        }
    }
    fclose(fp);
}


int  menu3(LinkList L)
{
    system("cls");  ///用来清屏的，删除回车前的输入
    while(1)
    {

        printf("===Gather books stastics within a peroid.====\n");
        printf("--1.Start to collect\n");
        printf("--0.Exit\n");
        printf("=============================================\n");
        int i;
        scanf("%d",&i);
        switch(i)
        {
            case 1:Books_In_A_Time(L);break;
            case 0: return 0;;
        }
    }
    return 0;
}




int main_menu(int i,LinkList L,Book b)
{

    while(1)  //使其之一保持循环直到输入退出选项0
    {
        system("cls");  ///用来清屏的，删除回车前的输入
        printf("===========Library Managerment System==================\n");
        printf("==== 1.Add/Modify/Delete books               ==========\n" );
        printf("==== 2.Search for books                      ==========\n" );
        printf("==== 3.Gather books stastics within a peroid.==========\n" );
        printf("==== 0.Exit                                  ==========\n" );
        printf("=======================================================\n");
        printf(">>>What do you want to do?\n>>>");
        scanf("%d",&i);

        switch(i)
        {
            case 1:  menu1(L,b); break;
            case 2:  menu2(L); break;
            case 3:  menu3(L); break;
            case 0:  Save2File(L);exit(0);
            default: break;
        }
    }
    return 0;
}
