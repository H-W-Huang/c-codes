
#include "iostream"
#include "algorithm"
#include "time.h"
#include "cstdio"

using namespace std;
int c[2000010];
int main()
{
    int N;
    int i,j,v,k=2;
    int n=1000000;
    while(k--){
    unsigned t=clock();
    freopen("data.txt","r",stdin);
    freopen("result.txt","at",stdout);
    cin>>N;
    for(i=0; i<n; i++) c[i]=100000000;
    for(i=0; i<N; i++)
    {
        scanf("%d",&v);
        for(j=n-1; j>=0; j--)
        {
            if(c[j]>v)
                c[j+1]=c[j];
            else
                break;
        }
        c[j+1]=v;
    }
//    the following costs much time
   // for(i=0; i<n; i++)
  //  cout<<c[i]<<" ";
    cout<<endl<<"time:"<<clock()-t<<endl;
    printf("%d",n);
    n=2000000;

    };

}

