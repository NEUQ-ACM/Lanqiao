#include<bits/stdc++.h>
using namespace std;

pair<int,int>order[100001];

int point[100001],ti[100001];
bool flag[100001];

int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=0;i<m;i++)
        cin>>order[i].first>>order[i].second;
    sort(order,order+m);

    for(int i=0;i<m;)
    {
        int j=i;
        while(j<m && order[j]==order[i]) j++;
        int t=order[i].first,id=order[i].second,cnt=j-i;
        i=j;
        point[id]-=t-ti[id]-1;
        if(point[id]<0) point[id]=0;
        if(point[id]<=3) flag[id]=0;

        point[id]+=cnt*2;
        if(point[id]>5) flag[id]=1;

        ti[id]=t;
    }

    for(int i=1;i<=n;i++)
        if(ti[i]<t){
            point[i]-=t-ti[i];
            if(point[i]<=3) flag[i]=0;
        }

    int res=0;
    for(int i=1;i<=n;i++) res+=flag[i];

    cout<<res<<endl;
	return 0;
}
