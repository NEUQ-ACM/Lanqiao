#include <bits/stdc++.h>
using namespace std;
bool vis[10];
int a[10], num, cnt = 0;
int cal(int l, int r)
{
    int re = 0;
    for (int i = l; i <= r; ++i)
    {
        re = 10 * re + a[i];
    }
    return re;
}
int dfs(int n)
{
    if (n == 9) //边界
    {
        for (int i = 0; i < 7; ++i)
        {
            for (int j = i + 1; j < 8; ++j)
            {
                int a = cal(0, i), b = cal(i + 1, j), c = cal(j + 1, 8);
                if (a * c + b == c * num)
                {
                    cnt++;
                }
            }
        }
    }
    for (int i = 1; i < 10; ++i)
    {
        if (vis[i] == 0)
        {
            vis[i] = 1;
            a[n] = i;
            dfs(n + 1);
            vis[i] = 0; //回溯
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int a, b, c;
    cin >> num;
    dfs(0);
    cout << cnt << endl;
    return 0;
}