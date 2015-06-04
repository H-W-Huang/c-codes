
#include<stdio.h>
#include<stdlib.h>
int  menu1()
{
    while(1)
    {
        printf("=============Add/Modify/Delete books==========\n");
        printf("--1.Add books\n");
        printf("--2.Search books\n");
        printf("--3.Delete books\n");
        printf("--0.Return \n");
        printf("==============================================\n");
        int i;
        scanf("%d",&i);
        switch(i)
        {
            case 1:printf("Added!\n"); break;
            case 2:printf("Search!\n"); break;
            case 3:printf("Delete!\n"); break;
            case 0:return 0;;
        }
    }
    return 0;
}

int menu2()
{
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
            case 1:printf("Added!\n"); break;
            case 2:printf("Search!\n"); break;
            case 3:printf("Delete!\n"); break;
            case 4:printf("Delete!\n"); break;
            case 0:return 0;;
        }
    }
}


int  menu3()
{
    while(1)
    {
        printf("===Gather books stastics within a peroid.====\n");
        printf("--0.Exit\n");
        printf("=============================================\n");
        int i;
        scanf("%d",&i);
        if(!i) return 0;
    }
    return 0;
}




int main_menu()
{
    while(1)  //使其之一保持循环直到输入退出选项0
    {
        system("cls");  ///用来清屏的，删除回车前的输入
        printf("==============Library Managerment System==================\n");
        printf("   1.Add/Modify/Delete books\n" );
        printf("   2.Search for books\n" );
        printf("   3.Gather books stastics within a peroid.\n" );
        printf("   0.Exit\n");
        printf("==========================================================\n");
        int i;
        printf(">>>What do you want to do?\n>>>");
        scanf("%d",&i);
        switch(i)
        {
            case 1:  menu1(); break;
            case 2:  menu2(); break;
            case 3:  menu3(); break;
            case 0: exit(0);
            default: break;
        }
    }
    return 0;
}
