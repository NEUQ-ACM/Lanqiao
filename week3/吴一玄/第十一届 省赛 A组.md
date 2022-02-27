## A 门牌制作

枚举

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    for(int i = 1; i <= 2020; ++i)
    {
        int x = i;
        while(x)
        {
            if(x % 10 == 2) ++ans;
            x /= 10;
        }
    }
    cout << ans << endl;
}
```

## B 既约分数

枚举

```cpp
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

int main()
{
    int ans = 0;
    for(int a = 1; a <= 2020; ++a)
        for(int b = 1; b <= 2020; ++b)
            if(gcd(a, b) == 1) ++ans;
    cout << ans << endl;
}
```

## C

复杂度显然是$O(20^2 )$的，直接模拟就行了

```cpp
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 1, res = 0;
    int x = 1, y = 1;
    for(int T = 2; T; ++T)
    {
        if(x == 1)
        {
            y = T; ++ans;
            while(y > 1)
            {
                ++x; --y;
                ++ans;
                if(x == 20 && y == 20) res = ans;
            }
        }
        else
        {
            x = T; ++ans;
            while(x > 1)
            {
                --x; ++y;
                ++ans;
                if(x == 20 && y == 20) res = ans;
            }
        }
        if(res) break;
    }
    cout << res << endl;
    return 0;
}
```

## D 七段码

还是暴力，$2^7$枚举每个二极管发不发光，然后判断一下是否联通即可。

```cpp
#include<bits/stdc++.h>
using namespace std;

int v[10][10];
int s[10];
int ans, vis[10];

void dfs(int x)
{
    vis[x] = 1;
    for(int i = 1; i <= 7; ++i)
        if(v[x][i] && s[i] && !vis[i]) dfs(i);
}

int main()
{
    v[1][2] = v[1][6] = 1;
    v[2][1] = v[2][7] = v[2][3] = 1;
    v[3][4] = v[3][7] = v[3][2] = 1;
    v[4][3] = v[4][5] = 1;
    v[5][4] = v[5][6] = v[5][7] = 1;
    v[6][1] = v[6][7] = v[6][5] = 1;
    v[7][2] = v[7][3] = v[7][5] = v[7][6] = 1;
    for(int i = 1; i < (1 << 7); ++i)
    {
        for(int j = 0; j < 7; ++j)
        {
            if((i >> j) & 1) s[j + 1] = 1;
            else s[j + 1] = 0;
        }
        memset(vis, 0, sizeof(vis));
        for(int j = 1; j <= 7; ++j)
            if(s[j]) {dfs(j); break;}
        int flag = 1;
        for(int j = 1; j <= 7; ++j)
            if(s[j] && !vis[j]) {flag = 0; break;}
        if(flag) ++ans;
    }
    cout << ans << endl;
}
```

## E 平面分割

不会

## F 成绩分析

弱智题，模拟。

```cpp
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10010;

int n, a[MAXN];
int mx, mn, sum;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    mx = -1, mn = 101, sum = 0;
    for(int i = 1; i <= n; ++i)
    {
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        sum += a[i];
    }
    cout << mx << "\n" << mn << "\n";
    printf("%.2f\n", 1.0 * sum / n);
}
```

## G 回文日期

还是模拟，枚举每一天判断即可，注意判断闰年。

```cpp
#include<bits/stdc++.h>
using namespace std;

int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void get(string s, int &y, int &m, int &d)
{
    y = m = d = 0;
    for(int i = 0; i < 4; ++i)
        y = y * 10 + s[i] - 48;
    for(int i = 4; i < 6; ++i)
        m = m * 10 + s[i] - 48;
    for(int i = 6; i < 8; ++i)
        d = d * 10 + s[i] - 48;
}

void to(string & s, int y, int m, int d)
{
    string a = "";
    while(y)
    {
        a += (char)(y % 10 + '0');
        y /= 10;
    }
    reverse(a.begin(), a.end());
    s = a;
    
    a = "";
    while(m)
    {
        a += (char)(m % 10 + '0');
        m /= 10;
    }
    if(a.size() == 1) a += "0";
    reverse(a.begin(), a.end());
    s += a;
    
    a = "";
    while(d)
    {
        a += (char)(d % 10 + '0');
        d /= 10;
    }
    if(a.size() == 1) a += "0";
    reverse(a.begin(), a.end());
    s += a;
}

bool Check(int y)
{
    if(y % 400 == 0) return 1;
    if(y % 100 == 0) return 0;
    if(y % 4 == 0) return 1;
    return 0;
}

int main()
{
    string s;
    cin >> s;
    int y, m, d;
    get(s, y, m, d);
    string ans1 = "", ans2 = "";
    int ok = 0;
    for(int i = y; i <= 9999; ++i)
    {
        if(Check(i)) Month[2]++;
        for(int j = (i == y ? m : 1); j <= 12; ++j)
        {
            for(int k = ((i == y && j == m) ? d + 1 : 1); k <= Month[j]; ++k)
            {
                string s;
                to(s, i, j, k);
                string p = s;
                reverse(p.begin(), p.end());
                if(p != s) continue;
                int flag = 0;
                if(s[0] == s[2] && s[0] == s[5] && s[0] == s[7]
                   && s[1] == s[3] && s[1] == s[4] && s[1] == s[6]) flag = 1;
                if(flag)
                {
                    ans2 = s;
                    if(ans1 == "") ans1 = s;
                    ok = 1; break;
                }
                else if(ans1 == "") ans1 = s;
            }
            if(ok) break;
        }
        if(ok) break;
        if(Check(i)) Month[2]--;
    }
    cout << ans1 << "\n" << ans2 << "\n";
    return 0;
}
```

## H 子串分值

单独考虑每个位置的贡献，设$s[i]$前一次出现的地方为$j$，后一次为$k$，那么$\forall \ l \in [j+1,i], r\in[i,k-1]$的区间都是符合条件的。

```cpp
#include<bits/stdc++.h>
using namespace std;

char s[100010];
int n; int pos[30];
int pre[100010], nxt[100010];

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++i)
    {
        pre[i] = pos[s[i] - 'a'];
        pos[s[i] - 'a'] = i;
    }
    for(int i = 0; i < 30; ++i) pos[i] = n + 1;
    for(int i = n; i; --i)
    {
        nxt[i] = pos[s[i] - 'a'];
        pos[s[i] - 'a'] = i;
    }
    long long ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        ans += (long long)(i - pre[i]) * (nxt[i] - i);
    }
    cout << ans << "\n";
    return 0;
}
```

## I 荒岛探测

求椭圆与三角形的面积交

计几神仙题，不会

## J 子串排序

正解不太会，有一个70分的做法。

首先长度为$n$的字符串逆序对最大为$\frac{n(n-1)}{2}$，由于题目要求字符串最短，所以我们考虑先构造一个逆序对全满的字符串，然后逐渐调整为所需的逆序对数。

调整方法是从后向前，每次把两个字符变成一样的，这样每次调整可以逆序对次数-1，比如d c b a(6) -> d c a a(5) -> c c a a(4)

然后如果这样还不行，那就把三个字符变成一样的，比如c c a a(4) -> c a a a(3)。

还需要让字符串字典序最小，那调整一下字符即可。

为什么是部分分呢，因为字符集的大小是26，所以这个方法只支持$V \leq 325$的数据。

```cpp
#include<bits/stdc++.h>
using namespace std;

char ans[210];

int main()
{
    int n; cin >> n;
    int m = 0;
    while(m * (m - 1) / 2 < n) ++m;
    int x = m * (m - 1) / 2 - n;
    ans[m] = 'a';
    for(int i = m - 1; i > 0; --i)
    {
        if(x > m / 2)
        {
            ans[i] = ans[i + 1]; --i;
            ans[i] = ans[i + 1]; --i;
            x -= 3;
        }
        else if(x > 0)
        {
            ans[i] = ans[i + 1]; --i;
            x -= 1;
        }
        if(i > 0) ans[i] = ans[i + 1] + 1;
    }
    for(int i = 1; i <= m; ++i) putchar(ans[i]);
    return 0;
}
```

