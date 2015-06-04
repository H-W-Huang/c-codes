// 18005 It is not ugly number

// 时间限制:1000MS  内存限制:65535K
// 提交次数:0 通过次数:0

// 题型: 编程题   语言: C++;C
// Description

// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence1, 2, 3, 4, 5, 6, 8, 9, 10, 12, ...shows the 
// first 10 ugly numbers. By convention, 1 is included. Then, here are the first 10 Not ugly numbers:7, 11, 13, 14, 17, 19, 
// 21, 22, 23, 26. Given the integer n, write a program to find and print the n'th Not ugly number.



// 输入格式

// First line is T, the number of cases.
// The T lines following. Each line of the input contains a positive integer n (n <= 100000000).


// 输出格式

// For each case, output the n'th Not ugly number .


// 输入样例

// 3
// 1
// 2
// 9


// 输出样例

// 7
// 11
// 23

// #include<stdio.h>
// void not_ugly_number()
// {




// }





// int main()
// {
//     int T;
//     scanf("%d",%T);
//     while(T--)
//     {

//     }
//     return );
// }

#include <iostream>
#include <queue>
using namespace std;
typedef pair<unsigned long,int> node_type;
int n[100000000];
main()
{

    //generates 1500 ugly numbers into result[];
    unsigned long result[1500];
    priority_queue<node_type,vector<node_type>,greater<node_type> > Q;
    Q.push(node_type(1,2));
    for(int i=0;i<1500;i++)
    {
        node_type node = Q.top();
        Q.pop();
        switch(node.second)
        {
            case 2:Q.push(make_pair(node.first*2,2));
            case 3:Q.push(make_pair(node.first*3,3));
            case 5:Q.push(make_pair(node.first*5,5)); 
        }
        result[i]=node.first;
    }

    int i,j,k=0;
    for(i=0,j=1;j<=100000000;j++)
    {
        if(j==result[i]) {i++;}
        else n[k++]=j;
    }
    int T,x;
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<n[x]<<endl;
    }
}


// int T;//k=0,i=0,count=0;
//     cin>>T;
//     while(T--)
//     {
//         int n;
//         int k=0,i=0,count=0;
//         cin>>n;

//         while(n)
//         {
//             if((k+1)==result[i]) {k++;i++;count++;/*cout<<count<<endl;*/}
//             else 
//             {
//                 k++;
//                 if(k-count==n) {cout<<k<<endl;break;}
//             }
//         }
//     }




//int k=1,i=0,count=0;
//     while(T--)
//    {
//        int n;
//        cin>>n;
//        
//        while(n)
//        {
//            
//            // cout<<k<<endl;
//            if(k==result[i])
//            {
//                // cout<<count<<endl;
//               k++;i++;
//            }
//            else{
//               n--;
//               if(!n)break;
//               k++;
//            }
//            // if(k==result[i]) count++;
//            // k++;i++;
//            // if((k-count)==n) break;
//        }
//        cout<<k<<endl;
//    }
