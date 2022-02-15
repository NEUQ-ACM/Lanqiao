#include <bits/stdc++.h>
using namespace std;
// 传送门：https://blog.csdn.net/qq_36306833/article/details/121872050
// 题解：https://blog.csdn.net/weixin_50533561/article/details/122753240?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164440729916780264043462%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164440729916780264043462&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-6-122753240.first_rank_v2_pc_rank_v29&utm_term=%E8%93%9D%E6%A1%A5%E6%9D%AF%E5%9B%9E%E8%B7%AF%E8%AE%A1%E6%95%B0&spm=1018.2226.3001.4187
// 状压dp
bool edge[30][30];
const int N = 22, M = 1 << 21; // 即M为二进制10000...000(21个0), M-1 = 21个1
long long dp[M][30];           // dp[i][j]代表状态为i时,走到第j个点时此时的方案数
// 数组要long long，否则溢出(别问我怎么知道的T_T)
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
bool judge(int x, int y)
{
    if (gcd(x, y) == 1)
        return true;
    else
        return false;
}
int main()
{
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j <= 21; j++)
            if (judge(i, j))
                edge[i][j] = 1;
    // 状压dp
    dp[1][1] = 1;                                                          //从1号点出发，此时状态为00000...0001
    for (int i = 1; i <= M - 1; i++)                                       // M-1后为111....11111(21个1)，枚举所有状态
        for (int j = 1; j <= 21; j++)                                      //枚举1-21点
            if (i >> (j - 1) & 1)                                          //从左边数第j个，此时若为真，则代表该状态中从左数第j个已走过
                for (int k = 1; k <= 21; k++)                              //若状态中含有该点，则枚举j联通的点，寻找以k为中转到达j点
                    if (edge[k][j] && (i - (1 << (j - 1))) >> (k - 1) & 1) //在未走j之前，状态为 i-(1<<j) 判断是否走过k点
                    //(i - (1 << (j - 1))) >> k & 1)判断i状态时没走j是否走了k
                    {
                        dp[i][j] += dp[(i - (1 << (j - 1)))][k]; //若走过k，说明到达j的状态i可以由挖去j但是含有k的状态完成
                    }
    long long ans = 0;
    for (int i = 2; i <= 21; i++) // dp[1111111..1111][i]代表最终走完并且终点为i点的情况
    //要从i=2开始！因为终点不可能是起点！
    {
        ans += dp[M - 1][i];
    }
    cout << ans;
    return 0;
}