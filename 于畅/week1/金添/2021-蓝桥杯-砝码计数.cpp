#include <bits/stdc++.h>
using namespace std;
// 传送门：https://blog.csdn.net/m0_46260869/article/details/115838370?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164441437816780366563231%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164441437816780366563231&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-115838370.first_rank_v2_pc_rank_v29&utm_term=%E7%A0%9D%E7%A0%81%E7%A7%B0%E9%87%8D&spm=1018.2226.3001.4187
// 类背包问题+dp
#define maxn 200000
int n;
long long sum = 0;
int cost[110];
bool dp[110][maxn]; // dp[i][j]代表重量j能否由前i个砝码称出
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cost[i], sum += cost[i];
    // sum为上界
    for (int i = 1; i <= n; i++)       //枚举1-n个物品
        for (int j = 1; j <= sum; j++) //枚举所有可能重量
        {
            dp[i][j] = dp[i - 1][j]; //之前能称的，现在仍然可以称
            if (dp[i-1][j] == 0)
            {
                if (cost[i] == j)
                    dp[i][j] = 1;
                if (dp[i - 1][j + cost[i]])
                    dp[i][j] = 1;
                if (dp[i - 1][abs(j - cost[i])])
                    dp[i][j] = 1;
            }
        }
    long long ans = 0;
    for (int i = 1; i <= sum; i++)
        if (dp[n][i])
            ans++;
    cout << ans;
    return 0;
}