#include<bits/stdc++.h>
using namespace std;

struct shop
    {
    int priority1=0;//优先级
    int order[10000] = {0};

    };
int main()
{
    int n;
    cin>>n;//N家外卖店

    int m;
    cin>>m;//几行

    int t;
    cin>>t;//结算时间

    shop a[n];
    int td;
    int ts;
    for(int i=0;i<m;i++)
    {
        cin>>ts;
        cin>>td;
        a[td-1].order[ts-1]++;
    }
        //计算优先级
        int count1=0;
    for(int i=0;i<n;i++)//每家店
    {
        for(int j=0;j<t;j++)//每个时刻
        {
            if(a[i].order[j] == 0)
            {
                a[i].priority1-=1;
                a[i].priority1 = a[i].priority1 >= 0 ? a[i].priority1:0;
            }
            else
            {
                a[i].priority1+=2*a[i].order[j];
            }
        }
        if(a[i].priority1 > 5)
        {
            count1++;
        }

    }
    cout<<count1;
    return 0;
}
/*
2 6 6
1 1
5 2
3 1
6 2
2 1
6 2
*/
