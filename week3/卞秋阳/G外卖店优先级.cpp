#include<bits/stdc++.h>
using namespace std;
vector<int>a[100001];
int n,m,t;
int b(int x)
{
    if(a[x].size()==0)
	{
		return 0;
	}
    int flag=0,p=2;
    for(int i=1;i<a[x].size();i++)
	{
        if(a[x][i]!=a[x][i-1])
		{
			p=max(0,p-(a[x][i]-a[x][i-1]-1));
		}		
        p+=2;
        if(p>5)
		{
			flag=1;
		}
    }
    p=max(0,p-(t-a[x][a[x].size()-1]));
    if(p<=3)
	{
		flag=0;
	}
    return flag;
}
int main()
{   
	cin>>n>>m>>t;
    for(int i=1;i<=m;i++)
	{
        int ts,id;
        cin>>ts>>id;
        a[id].push_back(ts);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
	{
        if(b(i))
		{
			ans++;
		}
    }
    cout<<ans;
    return 0;
}
