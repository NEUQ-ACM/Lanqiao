#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int n,t;
int dp[100005];
void dfs(int x)
{
	int w = v[x].size();
	for (int i = 0;i < w; i++)
	{
		int next = v[x][i];
		dfs(next);
		dp[x] = max(dp[x],dp[next] + w);
	}
	return;
}
int main()
{
	scanf("%d",&n);
	for (int i = 2;i <= n; i++)
	{
		scanf("%d",&t);
		v[t].push_back(i);
	}
	dfs(1);
	printf("%d\n",dp[1]);
	return 0;
}
