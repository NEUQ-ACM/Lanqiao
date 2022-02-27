#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> p[100005];
bool vis[100005];
int m,n,t,ans;
int main()
{
	cin>>n>>m>>t;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		p[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		sort(p[i].begin(),p[i].end());
		int num=0;
		for(int j=0;j<p[i].size();j++)
		{
			if(j==0&&p[i].size()!=0)
				num+=2;
			else
			{
				if(p[i][j]!=p[i][j-1])
				{
					num=num-(p[i][j]-p[i][j-1]-1);
				}
				if(num<0)
					num=0;
				num=num+2;
			}
		}
		if(num>5)
		{
			vis[i]=1;
		}
		if(p[i].size())
		{
			num=num-(t-p[i][p[i].size()-1]);
		}
		if(num<=3)vis[i]=0;
		if(vis[i]==1)ans++;
	}
	cout<<ans;
	return 0;
}

