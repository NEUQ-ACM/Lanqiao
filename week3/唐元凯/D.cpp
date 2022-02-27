#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 10;
int is_on[maxn], cnt, e[maxn][maxn], fa[maxn];

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void init() {
	e[1][2] = e[1][6] = 1;
	e[2][1] = e[2][7] = e[2][3] = 1;
	e[3][2] = e[3][4] = e[3][7] = 1;
	e[4][3] = e[4][5] = 1;
	e[5][4] = e[5][6] = e[5][7] = 1;
	e[6][1] = e[6][5] = e[6][7] = 1;
}

void dfs(int d) {
	if (d > 7) {
		for (int i = 1; i <= 7; i++)fa[i] = i;
		for (int i = 1; i <= 7; i++)
			for (int j = 1; j <= 7; j++)
				if (e[i][j] && is_on[i] && is_on[j]) {
					int x = find(i), y = find(j);
					if (x != y)fa[x] = y;
				}
		int k = 0;
		for (int i = 1; i <= 7; i++)
			if (is_on[i] && fa[i] == i)k++;
		if (k == 1)cnt++;
		return;
	}
	is_on[d] = 1;
	dfs(d + 1);
	is_on[d] = 0;
	dfs(d + 1);
}

int main() {
	init();
	dfs(1);
	cout << cnt;
}
