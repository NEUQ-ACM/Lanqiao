
#include <iostream>
using namespace std;
const long long MOD = 1e9 + 7;
int dp[5001][5001];
bool vis[5001][5001];
char str[5001];
int n;
long long gg() 
{
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    dp[0][0] = 1;
    vis[0][0] = true;

    for (int i = 1; i <= n; i++)
    {
        if (str[i - 1] == '(') 
        {
            for (int j = 1; j <= n; j++) 
            {
                dp[i][j] = dp[i - 1][j - 1];
                vis[i][j] = vis[i - 1][j - 1];
            }
        }
        else
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            vis[i][0] = vis[i - 1][0] | vis[i - 1][1];
            for (int j = 1; j <= n; j++) 
            {
                dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % MOD;
                vis[i][j] = vis[i - 1][j + 1] | vis[i][j - 1];
            }
        }
    }
    for (int i = 0; i <= n; i++) 
        if (vis[n][i] != 0) 
            return dp[n][i];
    return -1;
}
int main() 
{
    cin >> str;
    n = strlen(str);
    long long l = gg();
    reverse(str, str + n);//翻转
    for (int i = 0; i < n; i++) 
    {
        if (str[i] == ')') 
            str[i] = '(';
        else 
            str[i] = ')';
    }
    long long r = gg();
    cout << (l * r) % MOD;
    return 0;
}

