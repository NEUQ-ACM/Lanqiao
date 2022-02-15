#include<iostream>
#define ll long long
using namespace std;
const int N = 22, M = 1 << N;
ll f[M][N], ans;
bool vis[N][N];
int gsq(int x, int y)
{
	return y == 0 ? x : gsq(y, x % y);
}
int main()
{
	for (int i = 1; i <= 21; i++)
		for (int j = 1; j <= 21; j++)
			if (gsq(i, j) == 1)vis[i][j] = 1;
	f[2][1] = 1;
	for (int i = 2; i <= M - 2; i++)
		for (int j = 1; j <= 21; j++)
			if (i >> j & 1)
				for (int k = 1; k <= 21; k++)
					if (i - (1 << j) >> k & 1 && vis[k][j])
						f[i][j] += f[i - (1 << j)][k];
	for (int i = 2; i <= 21; i++)
		ans += f[M - 2][i];
	cout << ans;
}