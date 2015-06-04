#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<unsigned long,int> node_type;
int main()
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

    int T;  // The amount of cases
    cin>>T;
    //b_search_data[i] mean the count of non ugly number blow or equal i, i start from 1
    unsigned long b_search_data[1501];

    for (int i=0; i<1500; i++)
    {
        b_search_data[i] = result[i] - i - 1; // 
    }
    vector<int> search_data(b_search_data, b_search_data+1500);
    while(T--)
    {
        int n;
        int k=0,i=0,count=0;
        cin>>n;
        //upper_bound 将会返回数组中元素值为n-1的最大地址+1，vector是一个半闭半开区间
        //1 2 3 4 5 6 8 9 10
        //0 0 0 0 0 0 1 2 3 
        //0 1 2 3 4 5 6 7 8
        //第一个(n=1) : (6-0+1):7
        int position = upper_bound(search_data.begin(), search_data.end(), n-1) - search_data.begin();
        cout<<position + n<<endl;
    }
}

// int b_search(int n)
// {
//     int i=1500;
//     while(!(n==b_search_data[i/2]))
//     {
//         i/=2;
//     }
//     return i;
// }