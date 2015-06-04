//#include <iostream>
#include "stdio.h"
#include "menu.h"
#include "book.h"
#include "bm.h"
#define TURE 1
#define OK 1
#define FALSE 0
#define ERROR 0

int main()
{

    int i=0;
    Book b;
    LinkList L;
    Initial_list(L);
    loading(L);
    printf("Now test list:\n");
   main_menu(i,L,b);

    return 0;
}
