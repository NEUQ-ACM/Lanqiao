#include <bits/stdc++.h>
using namespace std;
// 素数筛+欧几里得拓展+快速幂
int num = 0;
long long e;
long long d = 212353;
long long n = 1001733993063167141;
long long C = 20190324;
long long p, q;
long long remp;
long long fast_power(long long a, long long b, long long c) //(a^b) %c
{
    a = a % c;
    long long ans = 1;
    while (b)
    {
        a = a % c;
        if (b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}
long long ex_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = ex_gcd(b, a % b, x, y);
    long long tmp = x;
    x = y;
    y = tmp - a / b * y;
    return d;
} //这个是解 ax+by=c的特殊解方程
int main()
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            p = i, q = n % i;
    } // p,q得到
    // p = 891234941, q = 1123984201
    // 那么可得d * e % sum == 1, 这是一个典型的求解ax=c(mod b)问题。
    // 也就是e*d =1(mod sum)，我们可以用扩展欧几里得算法来求解
    // 欧几里得拓展
    long long sum = (p - 1) * (q - 1);
    long long x, y;
    e = ex_gcd(d, sum, x, y);
    e = (e % sum + sum) % sum;
    // cout << e;
    // 现在求 C^e%d
    cout << fast_power(C, e, d);
    return 0;
}