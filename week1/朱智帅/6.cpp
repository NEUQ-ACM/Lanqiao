#include<iostream>
#include<set>
using namespace std;
int n, weight[101], dp[105][100005] = { 0 };
set<int>S;

int main()
{
	cin >> n;
	int i;
	dp[0][0] = 1;
	cin >> weight[0];
	dp[0][weight[0]] = 1;
	for (i = 1; i < n; i++)
	{
		cin >> weight[i];
		int j;
		for (j = 0; j <= 100000; j++)
		{
			if (dp[i - 1][j])
			{
				dp[i][j] = 1;
				dp[i][j + weight[i]] = 1;
				if (j > weight[i])
					dp[i][j - weight[i]] = 1;
				else dp[i][weight[i] - j] = 1;
			}

		}
	}
	int sum = 0;
	for (i = 1; i <= 100000; i++)
	{
		if (dp[n - 1][i])
		{
			sum++;
		}
	}
	cout << sum << endl;
	return 0;
}