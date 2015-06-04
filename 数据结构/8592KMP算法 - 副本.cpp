#include "stdio.h"
#include "string.h"
#define TRUE  1
#define FALSE  0
#define OK  1
#define ERROR  0
#define INFEASLBLE  -1
#define OVERFLOW  -2
#define MAXSTRLEN  10000    
typedef unsigned char SString[MAXSTRLEN+1]; 

void get_next(SString T,int next[])
{
    //i沿着模式串往前求出的是i+1的next，j用于代表、next值
    // abcdefg
    // 01
    // i(i+1)
    int i=1; int j=0;
    next[1]=0;
    while(i<=T[0])
    {
//        for(int k=1;k<=10;k++) printf("%d ",next[k]); putchar('\n');
        if(j==0||T[j]==T[i])
        {
            i++;
            j++;
            next[i]=j;
//            printf("Current j th value is %d , j+1 th value is %d \n",next[j-1],next[j]);
        }
        else j=next[j-1];
    }
}

int KMP(SString S,SString T,int next[]){
    int i=1,j=1,count=0,temp; //
    get_next(T,next);
    // for(j=1;j<=T[0];j++)
    //     printf("%d",next[j]);
    // printf("\n");
    // printf("pattern string:\n");
    // for(i=1;i<=T[0];i++) printf("%c", T[i]);putchar('\n');
    // while(i<=S[0])
    // {
    while(i<=S[0])  //不需要条件&&j<=T[0],这一次让i跑到底
    {
        if(j==0||S[i]==T[j]) //如果匹配成功,则移动至下一位
        {
            i++; j++;
        }
        else   j=next[j];//否则i不变，j移动到对应的next处 
        if(j==T[0]+1) {count++;j=next[j];}
    }
        
    // }
    printf("%d\n", count);
    return 0;
}



int main()
{
    int next[MAXSTRLEN+1];
    int i,j,n;
    SString a,b;
    char op[100],op1[20]="Query",op2[20]="Push_back",op3[20]="Push_front",ch;

    //接下来初始化主串
    ch=getchar();
    for(i=1;i<=MAXSTRLEN&&(ch!='\n');i++)    // 录入主串
    {
        a[i]=ch;
        ch=getchar();
    }
    a[0]=i-1;
    //接下来初始化模式串
    ch=getchar();
    for(i=1;i<=MAXSTRLEN&&(ch!='\n');i++)
    {
        b[i]=ch;
        ch=getchar();
    }
    b[0]=i-1;
    // printf("op:\n");
    scanf("%d",&n);getchar();
    i=0;
    // while((ch=getchar())!='\n') op[i++]=ch;
    while(n--)
    {
        // printf("n==%d\n", n);
        // gets(op);
        i=0;
        while((ch=getchar())!='\n') op[i++]=ch; op[i]='\0';
        if(strstr(op,op1))
        {
            // printf("Query!\n");
            KMP(a,b,next);
        }
        else if(strstr(op,op2))
        {
            int len=b[0];
            b[len+1]=op[10];
            b[0]=len+1;
            // printf("Push_back-->%c\n",op[10] );
            // for(i=1;i<=b[0];i++) printf("%c", b[i]);putchar('\n');
        }
        else if(strstr(op,op3))
        {
            int len=b[0],i;
            for(i=len;i>=1;i--) b[i+1]=b[i];
            b[1]=op[11];
            b[0]=len+1;
            // printf("Push_front--->%c",op[11]);
            // for(i=1;i<=b[0];i++) printf("%c", b[i]);putchar('\n');
        }
        // while((ch=getchar())!='\n') op[i++]=ch;
    }
    return 0;
}


// abcabc
// a
// 5
// Query
// Push_back b
// Query
// Push_front a
// Query

// aaaaa
// a
// 5
// Query
// Push_back a
// Query
// Push_front a
// Query




