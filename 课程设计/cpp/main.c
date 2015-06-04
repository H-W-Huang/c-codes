#include <stdio.h>
#include <stdlib.h>
#include "fileoper.h"
#include "menu.h"

int main()
{
    int choice;
    while(1)
    {
        choice = menu();
        switch(choice)
        {
        case 1:
            loadFromFile("Test.dat");
            break;
        case 2:
            saveToFile("Test.dat", NULL);
            break;
        case 0:
            return 0;
        }
    }
    return 0;
}
