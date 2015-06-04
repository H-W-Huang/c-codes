#include<stdio.h>
#include<string.h>
int main()
{
    char ch;
    //预先设定一个大的字符串，作为回溯的基础
    //程序有一个bug... 哪有= 错位到q的啊...
    char s[]="1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    while((ch=getchar())!=EOF)
    {
        int i;
       //for(i=0;i<strlen(s);i++)
       //{
       //    if(ch==' ')
       //    {
       //        putchar(ch);
       //        break;
       //    }
       //    if(s[i]==ch) 
       //    {   ch=s[i-1];
       //        putchar(ch);
       //        break;
       //    }
       //}
        for(i=1;s[i]&&s[i]!=ch;i++);
        if(s[i]) putchar(s[i-1]);
        else putchar(ch);


        //putchar(ch);
    }
    return 0;
}