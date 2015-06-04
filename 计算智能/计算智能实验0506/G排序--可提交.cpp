// G  排序

// Time Limit:1000MS  Memory Limit:65535K
// 题型: 编程题   语言: 无限制
// 描述

// 可怜的OYY在zayhero为他在新生赛上高调征友之后，依然找不到MM
// （T.T，都怪zayhero将题目出得太难），于是，OYY决定要改变自己，给其他人一个全新的印象。 改变的最重要一项，是将OYY凌乱的生活整理好，于是，OYY需要对生活中遇到的N种事情按其重要程度有大到小排序，有重点地解决问题。但是，严格按照这种规则生活是懒散的OYY难以持之以恒，所以，他容许自己作出一些轻微的调整。调整的操作是，OYY将最重要的那件事情放到最后才做。 现在，你需要根据OYY遇到的事情输出其做各种事情的顺序。


// 输入格式

// 第一行，一个整数N（2 <= N <= 10），表示事情的种类数。 第二行，N个整数Mi（1 <= Mi <= 100），表示事情的重要程度（越大表示越重要）。

// 输出格式

// 一行，含N个整数，表示OYY需要做的顺序。

// 输入样例

// 6
// 3 5 100 99 1 33
// 输出样例

// 99 33 5 3 1 100

// Provider

// a470086609

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int a[1000];
    for(i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(i=n-2;i>=0;i--) cout<<a[i]<<' ';
    cout<<a[n-1]<<' ';
    return 0;
}