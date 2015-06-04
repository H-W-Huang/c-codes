#include<stdio.h>
#include<string.h>
#define maxn 1010

int main()
{
    int n,a[maxn],b[maxn];
    int kase=0,i;
    //确保输入不为0
    while(scanf("%d",&n)==1&&n)
    {
        printf("Game %d:\n", ++kase);
        //输入答案序列
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(;;)
        {
            int A=0,B=0;
            for(i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
                if(a[i]==b[i]) A++; 
            }
            if(b[0]==0) break;
            //接下来是B的得出
            int d;
            for(d=1;d<=9;d++)
            {
                int c1=0,c2=0;
                int j;
                for(j=0;j<n;j++)
                {
                    if(a[j]==d) c1++;
                    if(b[j]==d) c2++;
                }
                if(c1<c2) B+=c1; else B+=c2;
                printf("   (%d,%d)\n",A,B-A );
            }
        }
    }
    return 0;



//    int lens;   //序列长度
//    int answer[len]; 
//    int reply[maxn];
//    int i=0;
//    for(i=0;i<len-1;i++) scanf("%d", &answer[i]);
//
//    while(scanf(%s))
}  