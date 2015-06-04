#include<stdio.h>
// int main()
// {   
    // int num,i,abc,de;
    // scanf("%d",&num);
    // for(abc=111;abc<=999;abc++)
        // for(de=11;de<=99;de++)
            // if(de==num)
            // {
                // int x=abc*(de/)
                // 
            // }
// }

#include<stdio.h>
#include<string.h>
int main()
{
    int count=0;
    char s[20],buf[99];
    scanf("%s",s);  //注意不需要取地址
    int abc,de;
    //接下来开始穷举，
    for(abc=111;abc<=999;abc++)
        for(de=11;de<=99;de++)
            {
                int x = abc*(de%10),y=abc*(de/10),z=abc*de;     //竖式需要用到的三个数
                sprintf(buf,"%d%d%d%d%d",abc,de,x,y,z);
                int  ok=1,i;
                for(i=0;i<strlen(buf);i++)
                    if(strchr(s,buf[i])==NULL) ok=0;
                if(ok)
                {
                    printf("<%d>\n", ++count);
                    printf("%5d\nX%4d\n-----\n%5d\n%4d\n-----\n%5d\n\n",abc,de,x,y,z );
                }
            }
            printf("The number pf solution=%d\n",count );
            return 0;
}