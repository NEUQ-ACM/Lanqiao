//20
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n,m,k;
int a[105][25];
int v[25];
int used[105];
int ans=inf;
bool pan()
{
	for(int i=1;i<=m;i++)
	{
		if(v[i]==0)
		{
			return false;
		}
	}
	return true;
}
void dfs(int now)
{
	if(now>ans)return;
	if(pan())
	{
		if(now<ans)
		{
			ans=now;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!used[i])
		{
			int vv[25];
			used[i]=1;
			for(int j=1;j<=k;j++)
			{
				vv[a[i][j]]=v[a[i][j]];
				v[a[i][j]]=1;
			}
			dfs(now+1);
			used[i]=0;
			for(int j=1;j<=k;j++)
			{
				v[a[i][j]]=vv[a[i][j]];
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
			v[a[i][j]]=1;
		}
	}
	if(!pan())
	{
		cout<<-1;
		return 0;
	}
	memset(v,0,sizeof(v));
	dfs(0);
	cout<<ans;
	return 0;
}
