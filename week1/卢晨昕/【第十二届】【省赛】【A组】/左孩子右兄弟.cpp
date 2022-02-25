#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int f[100005];
int num[100005];
int v[100005];
int d[100005];
void dfs(int now)
{
	if(now==1)return;
	int fa=f[now];
	d[fa]=max(d[fa],num[fa]+d[now]);
	dfs(fa);
}
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&f[i]);
		num[f[i]]++;
		v[f[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!v[i])
		{
			d[i]=1;
			dfs(i);
		}
	}
	cout<<d[1]-1;
	return 0;
}
