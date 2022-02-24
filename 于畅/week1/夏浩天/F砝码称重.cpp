//dp与伪背包

#include <iostream>
using namespace std;
long long sum = 0;
bool dp[110][200001]; // 重量j 前i个砝码
int w[110];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i], sum += w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (dp[i - 1][j] == 0)
            {
                if (w[i] == j)
                    dp[i][j] = 1;
                if (dp[i - 1][j + w[i]])
                    dp[i][j] = 1;
                if (dp[i - 1][abs(j - w[i])])
                    dp[i][j] = 1;
            }
        }
    long long en = 0;
    for (int i = 1; i <= sum; i++)
        if (dp[n][i])
            en++;
    cout << en;
    return 0;
}