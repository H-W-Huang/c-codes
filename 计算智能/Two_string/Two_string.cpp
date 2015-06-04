#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
using namespace std;

const int N = 1000002;

int next[N];
char S[N], T[N];
int slen, tlen;

void getNext(char *T,int *next)
{
    int i, j;
    i = 0; j = -1; next[0] = -1;
    while(i < tlen)
        if(j == -1 || T[i] == T[j])
            next[++i] = ++j;
        else
            j = next[j];
}

/*
返回模式串在主串S中出现的次数
*/
int KMP_Count(char *S,char *T,int *next,int slen,int tlen)
{
    int amount = 0;
    int i, j = 0;
    //先检查长度为1的情况
    if(slen == 1 && tlen == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }
    //长度不为1的情况
    getNext(T,next);
    for(i = 0; i < slen; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = next[j];
        if(S[i] == T[j])
            j++;
        if(j == tlen)
        {
            amount++;
            j = next[j];
        }
    }
    return amount;
}


int main()
{
    int next[5005];
    int i,j,n,k=0;
    char a[5005],b[5005];
    char op[5005],ch;
    const char *op1="Query",op2[20]="Push_back",op3[20]="Push_front";
    scanf("%s",a);
    scanf("%s",b);
    slen=strlen(a);
    tlen=strlen(b);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",op);
        // printf("%s\n", op);
        if(strstr(op,op1)) {printf("%d\n",KMP_Count(a,b,next,slen,tlen));}
        else if(strstr(op,op2))
        {
            scanf("%c",&ch);scanf("%c",&ch);
            // printf("%c\n", ch);
            b[tlen]=ch;
            b[tlen+1]='\0';
            tlen++;
            // printf("Now the b-string is %s\n",b );

        }
        else if(strstr(op,op3))
        {
            scanf("%c",&ch);scanf("%c",&ch);
            // printf("%c\n",ch );
            int k;
            for(k=tlen-1;k>=0;k--) b[k+1]=b[k];
            b[0]=ch;
            tlen++;
            // printf("Now the b-string is %s\n",b );
        }
    }
    // printf("n==%d\n",n );
    return 0;
}