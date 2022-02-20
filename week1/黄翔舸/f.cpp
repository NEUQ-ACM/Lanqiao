#include<iostream>
#define ll long long
using namespace std;
bool dp[105][200006];
int a[105], n, sum;
ll ans;
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];
			if (!dp[i][j]) {
				if (j == a[i])dp[i][j] = 1;
				if (dp[i - 1][j + a[i]])dp[i][j] = 1;
				if (dp[i - 1][abs(j - a[i])])dp[i][j] = 1;
			}
		}
	for (int i = 1; i <= sum; i++)
		if (dp[n][i])ans++;
	cout << ans;
}
