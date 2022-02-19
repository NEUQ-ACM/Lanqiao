#include <bits/stdc++.h>
using namespace std;
int vis[10004];
int dis[10004];
typedef struct node
{
    int x;
    int y;
} NODE;
vector<NODE> edge[10004];
void dfs(int st)
{
    for (int i = 0; i < edge[st].size(); i++)
    {
        int to = edge[st][i].x;
        if (!vis[to])
        {
            vis[to] = 1;
            vis[st] = 1;
            dis[to] = dis[st] + edge[st][i].y;
            // cout << "dis[" << to << "] = " << dis[to] << endl;
            dfs(to);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        NODE nd;
        nd.x = b;
        nd.y = c;
        edge[a].push_back(nd);
        nd.x = a;
        edge[b].push_back(nd);
    }
    memset(dis, 0, sizeof(dis));
    dfs(1);
    int maxlen = 0, Q, W, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] > maxlen)
            maxlen = dis[i], Q = i;
        dis[i] = vis[i] = 0;
    }
    dfs(Q);
    for (int i = 1; i <= n; i++)
        if (dis[i] > ans)
            ans = dis[i], W = i;
    // cout << ans << endl;
    cout << (11 + ans + 10) * ans / 2 << endl;
    return 0;
}