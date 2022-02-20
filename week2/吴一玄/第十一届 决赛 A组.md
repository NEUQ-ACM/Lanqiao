## 没找到官方题解， 答案仅供参考

## A

枚举，注意1不是合数。

$ans = 1713$

```cpp
bool Check(int n)
{
    for(int i = 2; i * i <= n; ++i)
        if(n % i == 0) return 1;
    return 0;
}

int main()
{
    int ans = 0;
    for(int i = 2; i <= 2020; ++i)
        if(Check(i)) ++ans;
    out(ans);
    return 0;
}
```

## B

也是枚举，注意判断一下闰年，如果当前年份or月份带有2，那么就不用再往下枚举了。

$ans = 1994240$

```cpp
const int days[13] =
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool Check(int n)
{
    if(n % 4) return 0;
    if(n % 400 == 0) return 1;
    if(n % 100 == 0) return 0;
    return 1;
}

bool two(int n)
{
    while(n)
    {
        if(n % 10 == 2) return 1;
        n /= 10;
    }
    return 0;
}

int main()
{
    int ans = 0;
    for(int year = 1900; year <= 9999; ++year)
    {
        if(two(year))
        {
            ans += 365;
            if(Check(year)) ++ans;
            continue;
        }
        for(int month = 1; month <= 12; ++month)
        {
            int daynum = days[month];
            if(Check(year) && month == 2) daynum = 29;
            if(two(month))
            {
                ans += daynum;
                continue;
            }
            for(int d = 1; d <= daynum; ++d)
            {
                if(two(d)) ++ans;
            }
        }
    }
    out(ans);
}
```

## C

DP，类似于LIS，为了保证“本质不同”，我们在转移$i$时，若枚举的$j$满足$s[j]==s[i]$，那么就中止枚举。

$ans = 3616159$

```cpp
int f[210];

int main()
{
    fastio();
    char s[210];
    cin >> (s + 1);
    int n = strlen(s + 1);
    s[0] = 'a' - 1;
    int ans = 0;
    f[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i - 1; ~j; --j)
        {
            if(s[j] == s[i]) break;
            if(s[j] < s[i]) f[i] += f[j];
        }
        ans += f[i];
    }
    out(ans);
}
```

## D

想打个表找规律，发现这个图形不太好构造，不会。

## E

枚举$1$开始的位置，然后$dfs$就行了。

$ans = 552$

```cpp
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int ans, vis[5][5];

void dfs(int x, int y, int num)
{
    if(num > 16)
    {
        ++ans;
        return;
    }
    for(int d = 0; d < 4; ++d)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 1 || nx > 4 || ny < 1 || ny > 4) continue;
        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        dfs(nx, ny, num + 1);
        vis[nx][ny] = 0;
    }
}

int main()
{
    for(int i = 1; i <= 4; ++i)
        for(int j = 1; j <= 4; ++j)
        {
            vis[i][j] = 1;
            dfs(i, j, 2);
            vis[i][j] = 0;
        }
    out(ans);
}
```

## F

我超，梅开二度

## G

好长，不会

## H

不妨把代价写出来，假设第$i$个人的答疑时间（不考虑离开的时间）是$a$，总时间是$b$，那么：

$ans = a_1 + (b_1+a_2) + (b_1+b_2 + a_3) + ... + (b_1+...+b_{n-1}+a_n)$

即：$(n-1)b_1+(n-2)b_2+...b_{n-1} +\sum_{i=1}^na_i$

这是一个经典问题，只需要对$b$升序排序即为最优。

```cpp
int n;
pair<ll, ll> t[MAXN];

int main()
{
    in(n);
    for(int i = 1; i <= n; ++i)
    {
        ll a, b, c;
        in(a, b, c);
        t[i] = make_pair(a + b + c, a + b);
    }
    sort(t + 1, t + 1 + n);
    ll ans = 0, now = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans += now + t[i].second;
        now += t[i].first;
    }
    out(ans);
    return 0;
}
```

## I

扫描线裸题，想不起来了写了个二维差分水60分。

感觉数据范围有点问题...题面里说的$60\%$的数据坐标小于1000，但是实际数据里是小于10000

```cpp
int n;
short sum[10010][10010];

int main()
{
    fastio();
    in(n);
    int mnx = inf, mxx = -inf, mny = inf, mxy = -inf;
    for(int i = 1; i <= n; ++i)
    {
        int x1, y1, x2, y2;
        in(x1, y1, x2, y2); ++x1, ++y1;
        mnx = min(mnx, x1);
        mxx = max(mxx, x2);
        mny = min(mny, y1);
        mxy = max(mxy, y2);
        
        ++sum[x1][y1], ++sum[x2 + 1][y2 + 1];
        --sum[x1][y2 + 1], --sum[x2 + 1][y1];
    }
    int odd = 0, even = 0;
    for(int i = mnx; i <= mxx; ++i)
        for(int j = mny; j <= mxy; ++j)
        {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            if(sum[i][j] & 1) ++odd;
            else if(sum[i][j] >= 2) ++even;
        }
    out(odd);
    out(even);
    return 0;
}
```

## J

一眼DP，$f_{i,0/i}$表示前$i$个位置，最后一次跳跃距离是否大于等于$p$的方案数。

$f_{i,0}=\sum_{i-p+1\leq j \leq i-1}f_{j,0}+f_{j,1}$

$f_{i,1}=\sum_{i-k\leq j \leq i-p}f_{j,0}$

搞一个矩阵快速幂，复杂度是$O(k^3logL)$的，可以混到60分。



 暴力杯名不虚传