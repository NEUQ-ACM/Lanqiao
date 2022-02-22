//答案：881012367360
//参考：https://blog.csdn.net/qq_36306833/article/details/121872050
//看得不是太懂，还在尝试理解，见谅
//尝试过dfs然后十分钟后给了错误答案（捂脸）
#include <iostream>
using namespace std;
long long dp[1 << 21][21];
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }//求最大公因数
bool vis(int state, int pos) //是否vis
{
    if ((state & (1 << pos)) != 0) //1 << pos == 2的pos次方
        return true;
    else 
        return false;
}

bool IsConnect(int x, int y) //是否相连
{
    if (x == 0 || y == 0) 
        return true;
    if (gcd(x + 1, y + 1) == 1) 
        return true;
    else 
        return false;
}

long long f(int state, int fp) 
{
    if (dp[state][fp] != -1) 
        return dp[state][fp];
    if (!vis(state, fp)) 
    return dp[state][fp]=0;

    long long ret = 0;

    for (int net = 0; net < 21; net++) 
    {
        if (!vis(state, net)) 
            continue;
        if (!IsConnect(net, fp)) 
            continue;
        ret += f(state - (1 << fp), net);
    }
    return dp[state][fp] = ret;
}

int main() 
{
    memset(dp, -1, sizeof(dp));
    long long int ans = 0;
    int finalState = (1 << (21)) - 1;
    dp[1][0] = 1;

    for (int i = 0; i < 21; i++) 
    {
        long long temp = f(finalState, i);
        ans += temp;
    }
    cout << ans;
    return 0;
}
