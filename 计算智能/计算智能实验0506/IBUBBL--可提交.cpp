// I  多少个Bubble

// Time Limit:30000MS  Memory Limit:65536K
// 题型: 编程题   语言: 无限制
// 描述

// 读入一行字符串（不多于800个字符，以回车结束），统计其中Bubble出现了多少次
// 输入样例

// Bubble if only BubbleBubble if only BubbleBubble if only Bubble.
// 输出样例

// 2
// Provider

// admin

#include <stdio.h>
#include <string.h>
int count_BUBBLE(char s[])
{
    char *c=s,b[]="Bubble";
    int n=0;
    //printf("%d\n",c);
    //puts(c);
    //printf("%d\n",c+1);
    //puts(c+1);
    while((c=strstr(c,b))!=NULL){n++;c=c+1;}
    return n;
}

char s[100000];
int main()
{

    gets(s);
    printf("%d\n",count_BUBBLE(s));
    return 0;
}
