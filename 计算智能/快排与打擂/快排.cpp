
#include "iostream"
#include "algorithm"
#include "time.h"
#include "cstdio"
#define n 2000000
using namespace std;
int data[2000010];
int main()
{
    int N;
    int i;
    unsigned t=clock();
    freopen("data.txt","r",stdin);
    cin>>N;
    for(i=0; i<N; i++) scanf("%d",&data[i]);
    sort(data, data+N);
    //the following costs much time
    //for(i=0; i<n; i++)
    //    cout<<data[i]<<" ";
    cout<<endl<<"time:"<<clock()-t<<endl;

}
