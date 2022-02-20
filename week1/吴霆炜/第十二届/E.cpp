#include <bits/stdc++.h>
using namespace std;
#define maxn 25
#define ll long long

int n = 21;
ll res;
ll dp[1 << 21][maxn];
bool vis[maxn][maxn];
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
			if ((i & (1 << (j - 1))) == 0) 
			continue;
			for (int k = 2;k <= n; k++)
			{
				if (i & (1 << (k - 1)) || (!vis[j][k])) 
				continue;
				int t = i + (1 << (k - 1));
				dp[t][k] += dp[i][j];
			}
		}
	}
	int m = (1 << 21) - 1;
	for (int i = 2;i <= n; i++)
	{
		res += dp[m][i];
	}
	printf("%lld\n",res);
	return 0;
}