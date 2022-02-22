#include<bits/stdc++.h>
using namespace std;
vector<int>g[100001];
int dfs(int j)
{
	int len=g[j].size(),ans=len,Max=0;
	for(int i=0;i<len;i++)
	{
		Max=max(Max,dfs(g[j][i]));
	}
	ans+=Max;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int j;
		cin>>j;
		g[j].push_back(i);
	}
	cout<<dfs(1);
	return 0;
}
