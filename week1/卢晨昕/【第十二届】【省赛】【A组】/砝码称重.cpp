#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int ans=0;
int w[105];
int v[100005];
map<int,int>lo[105];
void dfs(int now,int suml,int sumr)
{
	if(suml-sumr>0)v[suml-sumr]=1;
	if(lo[now][suml-sumr]==1)return;
	lo[now][suml-sumr]=1;
	if(now==n)return;
	dfs(now+1,suml,sumr);
	dfs(now+1,suml+w[now+1],sumr);
	dfs(now+1,suml,sumr+w[now+1]);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	sort(w+1,w+1+n);
	dfs(1,0,0);
	dfs(1,w[1],0);
	dfs(1,0,w[1]);
	for(int i=1;i<=100000;i++)
	{
		if(v[i]==1)ans++;
	}
	cout<<ans;
	return 0;
}
