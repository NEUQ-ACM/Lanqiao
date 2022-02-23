#include <bits/stdc++.h>
using namespace std;
// 传送门：http://oj.ecustacm.cn/problem.php?id=1509
int gcd(int a, int b)
{
    while(a%b)
    {
        int z=a%b;
        a=b;
        b=z;
    }
    return b;
}
int main()
{
    long long ans = 0;
    for (int i = 1; i <= 2020; i++)
        for (int j = 1; j <= 2020; j++)
            if (gcd(i, j)==1)
                ans++;
    cout << ans;
    return 0;
}