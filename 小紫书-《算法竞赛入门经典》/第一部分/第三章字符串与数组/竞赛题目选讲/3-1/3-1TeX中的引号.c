#include<stdio.h>
#include<string.h>
int main()
{
    //һ��һ���ַ��ش���
    int flag=0,i;
    char ch;
    while((ch=getchar())!=EOF) 
    {
        if(ch=='"')
        {
            if(flag==0){printf("%s"," �� " );flag=1;}
            else if(flag==1){printf("%s"," �� ");flag=0;}
            
        }
        else putchar(ch);            
    }
    return 0;
}