#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include<queue>

using namespace std;
const int N = 21, M = 1 << N;
long long dp[M][N];
bool ok[N][N];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main()
{
	for (int i = 1; i <= 21; i++) {
		for (int j = 1; j <= 21; j++) {
			if (gcd(i, j) == 1) ok[i - 1][j - 1] = true;
		}
	}
	dp[1][0] = 1;
	for (int i = 1; i <= M - 1; i++)
		for (int j = 0; j <= 20; j++)
			if (i >> j & 1)
				for (int k = 0; k <= 20; k++)
					if (i - (1 << j) >> k & 1 && ok[k][j])
						dp[i][j] += dp[i - (1 << j)][k];  
	long long ans = 0;
	for (size_t i = 1; i <= 20; i++) {
		ans += dp[M - 1][i];
	}
	cout << ans;
}
