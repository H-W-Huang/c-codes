#include <stdio.h>
#include <stdlib.h>
int menu()
{
    int choice;

    while(1)
    {
        system("cls"); //用来清屏的，删除回车前的输入
        printf("==========================\n");
        printf(" 1. Load data from File\n");
        printf(" 2. Save data to File\n");
        printf(" 0. Exit the program\n");
        printf("==========================\n");
        printf("Input your choice:");
        scanf("%d", &choice);
        if(choice>=0 && choice<=2)
        {
            break;
        }
    }
    return choice;
}
