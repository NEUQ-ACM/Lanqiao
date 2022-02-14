#include <bits/stdc++.h>
using namespace std;
int a[109], dp[3][100009];
int main()
{
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++) dp[1][j] = dp[2][j];	
		for (int j = 1; j <= sum; j++)
		{
			if(dp[1][j]) 
			{
				dp[2][j+a[i]] = 1;
				dp[2][abs(j-a[i])] = 1;
//				cout << "Ç°ÖÃ=" << j << " ";
//				cout << j+a[i] << " " << abs(j-a[i]) << endl;
 			}
		}
		dp[2][a[i]] = 1;
//		cout << a[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= sum; i++)
	{	
		
		if(dp[2][i]) ans++;
	}
	cout << ans;
	return 0;
}
