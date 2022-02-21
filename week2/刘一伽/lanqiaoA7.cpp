#include <iostream>
#define N 102
#define MAX_WEIGHT 100005
using namespace std;

int n, m, k, w[N], sum_weight, ans;
bool dp[N][MAX_WEIGHT << 2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		sum_weight += w[i];
	}
	dp[0][sum_weight * 2] = true;
	for (int i = 1; i <= n; ++i) {
		for (int j = sum_weight; j <= sum_weight * 3; ++j) {
			dp[i][j] = dp[i][j] || dp[i - 1][j] || dp[i - 1][j - w[i]] || dp[i - 1][j + w[i]];
		}
	}
	for (int i = 1; i <= sum_weight; ++i) {
		if (dp[n][sum_weight + i] || dp[n][sum_weight - i]) {
			++ans;
		}
	}
	cout << ans;
	return 0;
}

