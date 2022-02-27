#include <bits/stdc++.h>
using namespace std;
bool vis[102][100005];
int main()
{
    int n, num, sum = 0;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i)
    {
        cin >> num; // 1 4 6
        sum += num;
        a.push_back(num);
    }
    sort(a.begin(), a.end());

    memset(vis, 0, sizeof(vis));
    vis[0][a[0]] = 1;
    int temp;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j <= sum; ++j)
        {
            if (vis[i - 1][j])
            {
                vis[i][j] = 1;
                temp = fabs(j - a[i]);
                vis[i][j + a[i]] = 1;
                vis[i][temp] = 1;
                vis[i][a[i]] = 1;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= sum; ++i)
    {
        if (vis[n - 1][i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}