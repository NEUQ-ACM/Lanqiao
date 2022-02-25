#include <bits/stdc++.h>
using namespace std;
int n, m, sum = 0;
int minnum = 9999;
bool vis[11][11];
int a[11][11];
void dfs(int i, int j, int cnt, int item)
{
    if (item == sum / 2)
    {
        if (cnt < minnum)
        {
            minnum = cnt;
        }
    }
    if (i + 1 < n && vis[i + 1][j] && item < sum / 2)
    {
        vis[i + 1][j] = 0;
        dfs(i + 1, j, cnt + 1, item + a[i + 1][j]);
        vis[i + 1][j] = 1;
    } //下
    if (j + 1 < m && vis[i][j + 1] && item < sum / 2)
    {
        vis[i][j + 1] = 0;
        dfs(i, j + 1, cnt + 1, item + a[i][j + 1]);
        vis[i][j + 1] = 1;
    } //右
    if (i - 1 >= 0 && vis[i - 1][j] && item < sum / 2)
    {
        vis[i - 1][j] = 0;
        dfs(i - 1, j, cnt + 1, item + a[i - 1][j]);
        vis[i - 1][j] = 1;
    }
    if (j - 1 >= 0 && vis[i][j - 1] && item < sum / 2)
    {
        vis[i][j - 1] = 0;
        dfs(i, j - 1, cnt + 1, item + a[i][j - 1]);
        vis[i][j - 1] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    memset(vis, 1, sizeof(vis));
    vis[0][0] = 0;
    dfs(0, 0, 1, a[0][0]);
    cout << minnum << endl;
    return 0;
}