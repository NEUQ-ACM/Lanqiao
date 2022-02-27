//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n,m,t;
int ans=0;
int le[100005];
int v[100005];
vector<int>shop[100005];
struct node
{
	int ts,id;
}a[100005];
bool cmp(node a,node b)
{
	return a.ts<b.ts;
}
int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].ts>>a[i].id;
	}
	sort(a+1,a+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		shop[a[i].id].push_back(a[i].ts);
	}
	for(int i=1;i<=n;i++)
	{
		if(shop[i].size()==0)continue;
		int now=0;
		int tim=0;
		for(int j=0;j<shop[i].size();j++)
		{
			if(shop[i][j]!=tim)now=now-(shop[i][j]-tim-1);
			if(now<0)now=0;
			if(now<=3)v[i]=0;
			tim=shop[i][j];
			now+=2;
			if(now>5)v[i]=1;
		}
		if(tim!=t)now=now-(t-tim);
		if(now<=3)v[i]=0;
		if(v[i]==1)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
