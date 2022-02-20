#include <bits/stdc++.h>
using namespace std;
// 传送门：http://lx.lanqiao.cn/problem.page?gpid=T2695
// 完全二叉树基本性质
#define INF 0x7fffffff
long long root[100000];
long long a[100000];
int n;
int limit = 0;
int num = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> a[1];
    root[1] = a[1];
    num = 2;
    limit = 4;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i];
        root[num] += a[i];
        if (i + 1 == limit)
        {
            limit = limit * 2;
            num++;
        }
    }
    long long ans = 0;
    long long max1 = -INF;
    for (int i = 1; i <= num; i++)
    {
        if (max1 <= root[i])
        {
            max1 = root[i];
            ans = i;
        }
    }
    cout << ans;
    return 0;
}