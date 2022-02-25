#include <bits/stdc++.h>
using namespace std;
string s[35],t[4];
int dx[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};
string ans[35][55];
bool in(int x,int y)
{
	return x >= 0 && x < 30 && y >= 0 && y < 50;
}
void dfs(int x,int y)
{
	if (x == 29 && y == 49) return;
	for (int i = 0;i < 4; i++)
	{
		int tx = x + dx[i][0];
		int ty = y + dx[i][1];
		if ((!in(tx,ty)) || s[tx][ty] == '1' || (ans[tx][ty] != "x" && ans[x][y] + t[i] >= ans[tx][ty])) continue;
		ans[tx][ty] = ans[x][y] + t[i];
		dfs(tx,ty);
	}
}
int main()
{
	t[0] = "D"; t[1] = "L"; t[2] = "R"; t[3] = "U";
	for (int i = 0;i < 30; i++)
	{
		for (int j = 0;j < 50; j++)
		{
			ans[i][j] = "x";
		}
	}
	ans[0][0] = "";
	for (int i = 0;i < 30; i++)
	{
		cin >> s[i];
	}
	dfs(0,0);
	cout << ans[29][49] << endl;
	return 0;
}
