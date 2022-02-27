#include <bits/stdc++.h>
using namespace std;
#define N 100005
int f[N]; // you
vector<int> tree[N];
void dfs(int data)
{
    f[data] = tree[data].size();
    int maxn = 0;
    for (int i = 0; i < tree[data].size(); ++i)
    {
        int j = tree[data][i];
        dfs(j);
        maxn = max(maxn, f[j]);
    }
    f[data] += maxn;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, data;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> data;
        tree[data].push_back(i);
    }
    dfs(1);
    cout << f[1] << endl;
    return 0;
}
