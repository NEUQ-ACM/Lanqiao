#include <bits/stdc++.h>
using namespace std;
// floyed算法(会超时大概一分钟之后得到答案/捂脸）)
// 传送门：https://blog.csdn.net/qq_36306833/article/details/121872050
// 答案：10266837
int edge[2030][2030];
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}
int lcm(int x, int y)
{
    return x / gcd(x, y) * y;
}
int main()
{
    memset(edge, 0x3f, sizeof(edge));
    for (int i = 1; i <= 2021; i++)
        for (int j = i + 1; j <= 2021; j++)
        {
            if (j - i > 21)
                continue;
            int cost = lcm(i, j);
            edge[i][j] = cost;
            edge[j][i] = cost;
        }
    for (int k = 1; k <= 2021; k++)
        for (int i = 1; i <= 2021; i++)
            for (int j = 1; j <= 2021; j++)
            {
                edge[i][j] = min(edge[i][k] + edge[k][j], edge[i][j]);
            }
    cout<<edge[1][2021];
    // cout<<lcm(3,5);
    return 0;
}