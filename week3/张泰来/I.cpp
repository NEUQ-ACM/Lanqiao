#include <bits/stdc++.h>
using namespace std;
int n,m,k,t;
int dp[1 << 21],f[105];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i = 1;i <= n; i++)
	{
		for (int j = 1;j <= k; j++)
		{
			scanf("%d",&t);
			f[i] |= (1 << (t - 1));
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0] = 0;
	for (int i = 1;i <= n; i++)
	{
		for (int j = 0;j < (1 << m); j++)
		{
			int status = j | f[i];
			dp[status] = min(dp[status],dp[j] + 1);
		}
	}
	if (dp[(1 << m) - 1] < 1e9) printf("%d\n",dp[(1 << m) - 1]);
	else printf("-1\n");
	return 0;
}
