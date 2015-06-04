#include<stdio.h>
#include<string.h>
#include<ctype.h>
//isalpha存在于ctype头文件里


//首先写好大写字母与数字对应的镜像字符
//而且要注意一下，这里使用的是 指针数组！！
const char *rev="A   3  HIL JM O   STUVWXY51SE 5  8 ";
const char *msg[]={ "not a palindrome", "a regular palidrome", "a mirrored string", "a mirrored palindrome"};

//定义函数用判断字符是否为镜像字符,若无对应的字符，返回空格
char Mirror(char c)
{
    //可以使用isalpha函数盘不断是否为字符，这里不是用，自己用简单的判断判断语句来实现
    //printf("Mirror is %c\n",rev[c-'A']);
    if(c>='A'&&c<='Z') return rev[c-'A'];
    return rev[c-'0'+25];
}

int main()
{
    char s[100];
    // ch=getchar();
    scanf("%s",s);
    int m=1,p=1,i=0; //m,p两个变量是用来表示该字符串是否为回文串/镜像串的，初始为1
    //小写变大写
    //for(i=0;i<strlen(s);i++) if(s[strlen(s)-1]>='a'&&s[strlen(s)-1]<='z') s[strlen(s)-1]=s[strlen(s)-1]+'A'-'a';
    //注意这里条件的设定
    for(i=0;i<=(strlen(s)+1)/2;i++)
    {
        if(s[i]!=s[strlen(s)-1-i]) p=0;  //检查回文串
        //printf("NUM:%d---p is %d\n",i,p);
        //char ch=Mirror(s[i]);
        if(Mirror(s[i])!=s[strlen(s)-1-i])  m=0;
        //printf("NUM:%d---s[strlen(s)-1-i] is %c and ch is %c\n",i,s[strlen(s)-1-i],ch);
        //printf("NUM:%d---m is %d\n",i,m);
    }
    printf("%s\n", msg[2*m+p]); 
    //putchar(s[2]);
    return 0;
}