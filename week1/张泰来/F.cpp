#include <bits/stdc++.h>
using namespace std;
int n,sum,ans;
int a[105];
bool dp[100005];
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",a + i);
		sum += a[i];
	}
	dp[0] = true;
	for (int i = 1;i <= n; i++)
	{
		for (int j = sum;j >= a[i]; j--)
		{
			dp[j] |= dp[j - a[i]];
		}
	}
	for (int i = 1;i <= n; i++)
	{
		for (int j = 0;j <= sum - a[i]; j++)
		{
			dp[j] |= dp[j + a[i]];
		}
	}
	for (int i = 1;i <= sum; i++)
	{
		if (dp[i]) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
