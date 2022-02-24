#include <bits/stdc++.h>
using namespace std;
int n = 21;
long long ans;
long long dp[1 << 21][25];
bool vis[25][25];
int gcd(int x,int y)
{
	return y > 0 ? gcd(y,x % y) : x;
}
int main()
{
	for (int i = 1;i <= n; i++)
	{
		for (int j = i + 1;j <= n; j++)
		{
			if (gcd(i,j) == 1) vis[i][j] = vis[j][i] = true;
		}
	}
	dp[1][1] = 1;
	for (int i = 1;i < (1 << n); i += 2)
	{
		for (int j = 1;j <= n; j++)
		{
			if ((i & (1 << (j - 1))) == 0) continue;//必须去过j节点
			for (int k = 2;k <= n; k++)
			{
				if (i & (1 << (k - 1)) || (!vis[j][k])) continue;//不能已经去过k节点,必须要有边 
				int t = i + (1 << (k - 1));
				dp[t][k] += dp[i][j];
			}
		}
	}
	int m = (1 << 21) - 1;
	for (int i = 2;i <= n; i++)
	{
		ans += dp[m][i];
	}
	printf("%lld\n",ans);
	return 0;
}
