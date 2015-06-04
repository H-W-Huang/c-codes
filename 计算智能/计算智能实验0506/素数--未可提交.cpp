//H  素数
//
//Time Limit:500MS  Memory Limit:1000K
//题型: 编程题   语言: 无限制
//描述
//
//数学对于计算机学是很重要的，大一的高数就曾经（或即将）令一批又一批人饮恨。这里就是一个数学问题，当然，它不需要用到高深的高数知识。
//给出n（1<=n<=100000），问1到n之间有几个素数。

//输入格式
//
//第1行，1个整数T（T<=100000），表示共有T组测试数据
//第2---第T+1行，每行1个整数，表示测试数据n
//输出格式
//
//对于每个测试数据，输出1行，每行1个数，表示1到n之间的素数个数
//输入样例
//
//5
//1
//2
//100
//1000
//5000
//
//输出样例
//
//0
//1
//25
//168
//669
//Provider
//
//admin

// #include<stdio.h>


// int Is_prime(int n,int last_prime)
// {
//     int m=last_prime;
//     if(n==0||n==1) return 0;
//     for(m=2;m<=n/2;m++)
//         if(n%m==0)  break;
//     if(m>n/2) return 1;
//     return 0;
// }//finish!


// // int make_prime_num_table(int a[])
// // {
//     // int i;
//     // for(i=2;i<=100000;i++)
//     // {
//         // if(Is_prime(i)){a[i]=(++c);/*printf("%d\n",a[i]);*/}
//     // }
//     // return 0;
// // }

// int p_table[100005];
// int main()
// {
//     int n,last_prime=2;
//     int i,j=0, c=0;
//     for(i=0;i<=100000;i++)
//     {
//         if(Is_prime(i,last_prime)){/*printf("%d is a prime number!!\n",i);*/last_prime=i;p_table[j++]=(++c);/*printf("%d\n",a[i]);*/}
//         else{p_table[j++]=c;}
//     }
//     scanf("%d",&n);
//     printf("%d\n",p_table[n]);
//     return 0;
// }


//解法
//1. 打表

//打表1

// #include<stdio.h>
// int Is_prime(int n)
// {
//     int m;
//     if(n==0||n==1) return 0;
//     for(m=2;m<=n/2;m++)
//         if(n%m==0)  break;
//     if(m>n/2) return 1;
//     return 0;
// }//finish!



// int p_table[100005];
// int main()
// {
//     freopen("out.txt","w",stdout);
//     int n;
//     int i,j=0, c=0;
//     for(i=0;i<=100000;i++)
//     {
//         if(Is_prime(i)){p_table[j++]=(++c);}
//         else{p_table[j++]=c;}
//     }
//     // scanf("%d",&n);
//     for(i=0;i<=100000;i++)
//     printf("%d,",p_table[i]);
//     return 0;
// }




// #include<stdio.h>
// int Is_prime(int n)
// {
//     int m;
//     if(n==0||n==1) return 0;
//     for(m=2;m<=n/2;m++)
//         if(n%m==0)  break;
//     if(m>n/2) return 1;
//     return 0;
// }//finish!



// int p_table[100005];
// int main()
// {

//     int n;
//     int i,j=0, c=0;
//     for(i=0;i<=100000;i++)
//     {
//         if(Is_prime(i)){p_table[j++]=i;}
//     }
//     scanf("%d",&n);
//     //for(i=0;i<=9592;i++) printf("%d ",p_table[i]);
//     if(n==1) printf("%d\n",0);
//     else if(n>=99991) printf("%d\n",9592);
//     else 
//     for(i=0;i<=10000;i++)
//      {
//         if(n>=p_table[i]&&n<p_table[i+1])
//             printf("%d\n",i+1);
//      }   
//     return 0;
// }
