## A 卡片

显然答案不会太大，直接枚举即可。

答案：$3181$

```cpp
int num[10];

bool Check(int x)
{
    while(x)
    {
        if(num[x % 10]) --num[x % 10];
        else return 0;
        x /= 10;
    }
    return 1;
}

int main()
{
    for(int i = 0; i < 10; ++i) num[i] = 2021;
    int ans = 1;
    while(1)
    {
        if(Check(ans)) ++ans;
        else break;
    }
    out(ans);
    return 0;
}
```

## B 直线

一共有$420$个点，直接枚举点对，然后暴力判重即可。

判断方法：两条直线$l1,l2$相同的充要条件是$l1$上任意两点均在$l2$上

若点$Q$在直线$l$上，那么任取$l$上两点$p1,p2$，则有：$(Q-p1) \times (p2-p1)=0$

答案：$40257$

```cpp
struct Vector
{
    ll x, y;
    Vector(ll nx = 0, ll ny = 0) 
    {
        x = nx;
        y = ny;
    }
};

ll operator * (const Vector &a, const Vector &b)
{
    return a.x * b.y - a.y * b.x;
}

Vector operator - (const Vector &a, const Vector &b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

struct Line
{
    Vector p1, p2;
}s[200010];
int cnt;

inline bool Check(Vector q, Line a)
{
    ll val = (q - a.p1) * (a.p2 - a.p1);
    if(val == 0) return 1;
    return 0;
}

inline bool isok(Line a, Line b)
{
    if(Check(a.p1, b) && Check(a.p2, b)) return 1;
    return 0;
}

const int X = 20;
const int Y = 21;

int main()
{
    for(int sx = 0; sx < X; ++sx)
        for(int sy = 0; sy < Y; ++sy)
            for(int ex = 0; ex < X; ++ex)
                for(int ey = 0; ey < Y; ++ey)
                {
                    if(sx == ex && sy == ey) continue;
                    Line now;
                    now.p1 = Vector(sx, sy);
                    now.p2 = Vector(ex, ey);
                    int flag = 1;
                    for(int i = 1; i <= cnt; ++i)
                        if(isok(s[i], now)) {flag = 0; break;}
                    if(flag)
                    {
                        s[++cnt] = now;
                    }
                }
    out(cnt);
}
```

## C 货物摆放

拆分成若干个数相乘，则可以用质因数把这若干个数拼出来。

$2021041820210418 = 2^1 * 3^3 * 17^1 * 131^1 * 2857^1 * 5882353^1$ 

考虑$a,b,c$有多少种构造，首先考虑只出现过一次的质因数，显然有$3^5$种

然后$3$出现了多次，不过这里次数比较少，就不推公式了，直接枚举得$10$种。

那么答案是$3^5*10=2430$种。

也可以直接$dfs$然后判重，这样复杂度是$O(3^8*log(3^8))$的。

质因数分解的代码就不需要放了吧...

## D 路径

连边然后$dijkstra$。

答案：$10266837$

```cpp
ll gcd(ll a, ll b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

vector<int> G[MAXN];
vector<ll> V[MAXN];

inline void add(int u, int v, ll z)
{
    G[u].push_back(v);
    V[u].push_back(z);
}

struct Node
{
    int u; ll dis;
    bool operator < (const Node &x) const
    {
        return dis > x.dis;
    }
};
ll dis[MAXN];

ll dijkstra(int s, int t)
{
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<Node> q;
    q.push((Node){s, 0}); dis[s] = 0;
    while(!q.empty())
    {
        Node x = q.top(); q.pop();
        if(x.dis != dis[x.u]) continue;
        for(int i = 0; i < (int)G[x.u].size(); ++i)
        {
            int y = G[x.u][i]; ll z = V[x.u][i];
            if(dis[y] > dis[x.u] + z)
            {
                dis[y] = dis[x.u] + z;
                q.push((Node){y, dis[y]});
            }
        }
    }
    return dis[t];
}

int main()
{
    for(int a = 1; a <= 2021; ++a)
        for(int b = 1; b <= 2021; ++b)
        {
            if(a == b) continue;
            if(abs(a - b) > 21) continue;
            ll z = (ll)a * b / gcd(a, b);
            add(a, b, z);
        }
    cout << dijkstra(1, 2021) << endl;
    return 0;
}
```

## E 回路计数

经典哈密顿回路，状压$DP$就完了。

状态$(pos,s)$表示当前位于$pos$，走过的点集为$s$。

复杂度：$O(2^nn^2logn)$

答案：$881012367360$

```cpp
int gcd(int a, int b)
{
    if(!b) return a;
    return gcd(b, a % b);
}

ll dp[21][1 << 21];

ll dfs(int pos, int s)
{
    if(dp[pos][s] != -1) return dp[pos][s];
    ll & ans = dp[pos][s]; ans = 0;
    for(int i = 0; i < 21; ++i)
        if(((s >> i) & 1) && (gcd(pos + 1, i + 1) == 1))
            ans += dfs(i, s ^ (1 << i));
    return ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    cout << dfs(0, (1 << 21) - 1) << endl;
}
```

## F 砝码称重

显然是个背包，负数的处理平移一下就好了。

$bitset$快的飞起。

```cpp
#include<bits/stdc++.h>
using namespace std;

int n, a[110], sum;
bitset<200010> f;

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    f[100000] = 1;
    for(int i = 1; i <= n; ++i)
    {
        f |= (f << a[i]);
        f |= (f >> a[i]);
    }
    int cnt = 0;
    for(int i = 100001; i <= 100000 + sum; ++i)
        if(f[i]) ++cnt;
    printf("%d\n", cnt);
    return 0;
}
```

## 剩下的题

都没什么想法，统统写暴力。

可以参考：

```
如何评价第十二届蓝桥杯第一场省赛？ - hycc的回答 - 知乎
https://www.zhihu.com/question/455250575/answer/1841703353
```

