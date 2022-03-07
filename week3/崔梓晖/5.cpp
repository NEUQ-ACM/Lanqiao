#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10010;
int f[110][N];
int a[110];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int main() {
	int n; cin >> n;
	int d = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		d = gcd(d, a[i]);
	}
	if (d != 1)cout << "INF" << endl;
	else {
		f[0][0] = 1;
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= 10000; ++j) {
				f[i][j] = f[i - 1][j];
				if (j >= a[i])f[i][j] |= f[i][j - a[i]];
			}
		}
		int res = 0;
		for (int i = 0; i <= 10000; ++i)
			if (!f[n][i])res++;
		cout << res << endl;
	}
	return 0;
}
