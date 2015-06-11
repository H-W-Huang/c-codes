// 18025 小明的密码（一天后，再提交）
// Description
// 小明的密码由N（1<=N<=20）个数字构成，每个数字都可以是0至9中任意一个数字，但小明的密码还有
// 一个特点就是密码中连续的M（1<=M<=N）个数字的和是质数，现给定M和N，求满足条件的密码共有多少
// 个？

/*
Here is the problem:
    You are given a array whose elements are numbers ranging from 0 to 9, the length of the array is between 1 and 20 (1<=len<=20)
    One characterstic of the array is that for evrey sub-array whose lenght is M (1<=M<=len),the sum of the elements in the sub-array is a prime number.
    Now,input the len and the M ,and return how many arrays that meet the requriement.

    **  Time Limit:1000ms ; Memory Limit :65535K  **

    Here are some examples to help me to express more precisely:
    No.1:
    if len=1 and M=1 
    possible arrays are: {1},{2},{3},{4},{5},{6},{7},{8},{9},
    among which {2},{3},{5},{7} meet the requirement, so the answer is 4;
     
    if len=2 and M=1;
    possible arrays
    {00},{10},{20},{30},{40},{50},{60},{70},{80},{90},     4  [0,9 ]     
    {01},{11},{12},{31},{41},{51},{61},{71},{81},{91},     4  [1,10]       
    {02},{12},{22},{32},{42},{52},{62},{72},{82},{92}, 4   5  [2,11]   
    {03},{13},{32},{33},{43},{53},{63},{73},{83},{93}, 4   4  [3,12]  
    {04},{14},{42},{34},{44},{54},{64},{74},{84},{94},     4  [4,13] 
    {05},{15},{52},{35},{45},{55},{65},{75},{85},{95}, 4   4  [5,14]  
    {06},{16},{62},{36},{46},{56},{66},{76},{86},{96},     3  [6,15] 
    {07},{17},{72},{37},{47},{57},{67},{77},{87},{97}, 4   3  [7,16]  
    {08},{18},{82},{38},{48},{58},{68},{78},{88},{98},     3  [8,17] 
    {09},{19},{92},{39},{49},{59},{69},{79},{89},{99},     3  [9,18] 
    the answer is 16

    
    2 3 5 7 11 13 17 19
    
    if len=2 and M=2;
    {00},{10},{20},{30},{40},{50},{60},{70},{80},{90},    4  [0,9]     
    {01},{11},{12},{31},{41},{51},{61},{71},{81},{91},    4  [1,10]       
    {02},{12},{22},{32},{42},{52},{62},{72},{82},{92},    5  [2,11]   
    {03},{13},{32},{33},{43},{53},{63},{73},{83},{93},    4  [3,12]  
    {04},{14},{42},{34},{44},{54},{64},{74},{84},{94},    4  [4,13] 
    {05},{15},{52},{35},{45},{55},{65},{75},{85},{95},    4  [5,14]  
    {06},{16},{62},{36},{46},{56},{66},{76},{86},{96},    3  [6,15] 
    {07},{17},{72},{37},{47},{57},{67},{77},{87},{97},    3  [7,16]  
    {08},{18},{82},{38},{48},{58},{68},{78},{88},{98},    3  [8,17] 
    {09},{19},{92},{39},{49},{59},{69},{79},{89},{99},    3  [9,18] 
    the answer is 37

    I tried brute force, but... you know.

    37 
    32 4 1









*/
// 输入格式
// 两个数N M


// 输出格式
// 满足条件的密码总数



// 输入样例
// 1 1




// 输出样例
// 4


//使用回溯法

/*****
    题目过了，但是效果不好。超过了1000ms，具体如下：
    提交编号    称呼  题目编号    评判结果    运行时间    内存用量    语言  提交时间
    1228287 201430340106    18025   通过  1777 ms 3866 K  G++ 2015-06-11 09:01:24.589
*****/

#include <cstdio>
#include <cmath>
#include <algorithm>
int prime_table[200]={0};
int sum=0,tot=0,n,m;
int a[10000];


//打出素数表
int make_prime_table(int prime_table[])
{
    int i,j,n=sqrt(200)+1;

    for(i=2;i<=n;i++)
        for(j=2;j<200/i;j++)
            prime_table[i*j]=1;
    return 0;
}


// m==1的情况可以解决了
int  dfs(int cur)
{
    //设置边界
    if(cur==n+1) { tot++; return 0;}
    else
        for(int i=0;i<=9;i++) //对每一位从0到9试一遍
        {
            int ok=1;
            sum=0;
            a[cur]=i;
            for(int j=cur-m+1;j<=cur;j++)
            {
                sum+=a[j];
            }
            if(prime_table[sum]==0||cur<m)
                dfs(cur+1);
        }
    return 0;
}

int main()
{
    int c;
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        int cur=1;
        tot=0;
        make_prime_table(prime_table);
        prime_table[1]=1; prime_table[0]=1;
        dfs(cur);
        printf("%d\n",tot);
    }
   return 0;
}



//backup
/*int  dfs(int cur)
{
    //设置边界
    if(cur==n-m+1) { tot++; return 0;}
    else
        for(int i=0;i<=9;i++) //对每一位从0到9试一遍
        {
            sum=0;
            a[cur]=i;
            printf("m==%d,cur==%d \n",m,cur );
            if(cur>=m)
            {
                for(int k=cur;k<cur+m;k++) sum+=a[cur];
                printf("sum==%d\n",sum);
                if(prime_table[sum]==0)
                {
                    a[cur]=i;
                    dfs(cur+1);                
                }
            }
            
        }
    return 0;
}*/


/*int  dfs(int cur)
{
    //设置边界
    if(cur==n+1) { tot++; return 0;}
    else
        for(int i=0;i<=9;i++) //对每一位从0到9试一遍
        {
            sum=0;
            a[cur]=i;
            printf("m==%d,cur==%d \n",m,cur );
            // if(cur>=m)
            // {
                for(int k=cur-m+1;k<=cur;k++) sum+=a[cur];
                printf("sum==%d\n",sum);
                if(prime_table[sum]==0)
                {
                    a[cur]=i;
                    dfs(cur+1);            
                }
            // }
            
        }
    return 0;
}
*/

