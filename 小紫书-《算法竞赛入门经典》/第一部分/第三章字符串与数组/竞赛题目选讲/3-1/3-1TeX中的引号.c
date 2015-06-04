#include<stdio.h>
#include<string.h>
int main()
{
    //一个一个字符地处理
    int flag=0,i;
    char ch;
    while((ch=getchar())!=EOF) 
    {
        if(ch=='"')
        {
            if(flag==0){printf("%s"," “ " );flag=1;}
            else if(flag==1){printf("%s"," ” ");flag=0;}
            
        }
        else putchar(ch);            
    }
    return 0;
}