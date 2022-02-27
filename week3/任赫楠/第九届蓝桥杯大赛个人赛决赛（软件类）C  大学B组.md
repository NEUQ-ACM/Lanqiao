# 第九届蓝桥杯大赛个人赛决赛（软件类）C  大学B组

---

##     A    换零钞

```c++
#include<iostream>
using namespace std;
const int N = 200;
int res = 1e9;
int main() {
    for (int i = 1; i <= 200 / 21; i++) {
        int j = (200 - 21 * i);
        if (j % 5 == 0) {
            res = min(res, 11 * i + j / 5);
        }
    }
    cout << res;
    return 0;
}
```

---

##    B    激光样式

```c++
#include<iostream>
using namespace std;
const int N = 40;
int f[N][2];
int main() {
    f[0][0] = 1;
    for (int i = 1; i <= 30; i++) {
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i - 1][0];
    }
    cout << f[30][0] + f[30][1];
    return 0;
}
```

---

##     C    格雷码

```c++
//a ^ ((a& (-a)) << 1)
```

---

##     D    调手表

```c++
#include<iostream>
#include<queue>
#include<cstring>
#define mm(a,x) memset(a,x,sizeof a)
#define inf 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
int n, k;
int dist[N];
int res;
void bfs(int u) {
    queue<int > q;
    mm(dist, inf);
    q.push(u);
    dist[u] = 0;
    while (q.size()) {
        int t = q.front();
        q.pop();
        int p = (t + 1) % n;
        if (dist[p] == inf) {
            dist[p] = dist[t] + 1;
            q.push(p);
        }
        p = (t + k) % n;
        if (dist[p] == inf) {
            dist[p] = dist[t] + 1; 
            q.push(p);
        }
    }
}
int main() {
    cin >> n >> k;
    bfs(0);
    for (int i = 0; i <= n - 1; i++) {
        res = max(res, dist[i]);
    }
    cout << res;
    return 0;
}
```

---

##     E    搭积木

```c++
#include<iostream>
#include<set>
#include<map>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
#define MOD 1000000007
typedef long long LL;
const int maxn = 110;
LL dp[maxn][maxn];
int check[maxn][maxn];
int main() {
    int n, m;
    char str[maxn];
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str + 1);
        for (int j = 1; j <= m; j++) {
            check[i][j] = check[i][j - 1];
            if (str[j] == 'X') {
                check[i][j]++;
            }
        }
    }
    LL ans = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = m; j >= i; j--) {
            if (check[n][j] - check[n][i - 1] == 0) {
                ans++;
                dp[i][j] = dp[i][j + 1] + dp[i - 1][j] - dp[i - 1][j + 1] + 1;
            }
        }
    }
    for (int t = n - 1; t > 0; t--) {
        for (int i = 1; i <= m; i++) {
            for (int j = m; j >= i; j--) {
                if (check[t][j] - check[t][i - 1] == 0) {
                    ans = (ans + dp[i][j]) % MOD;
                    dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j + 1] - dp[i - 1][j + 1]) % MOD;
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}

```

---

##     F    矩阵求和

```c++
#include<iostream>
#include<set>
#include<map>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;
#define ll long long
const ll N = 1e7 + 5;
const ll p = 1e9 + 7;
ll phi[N], s[N], cnt, vis[N], prim[N];
void init() {
    phi[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) {
            phi[i] = i - 1;
            prim[++cnt] = i;
        }
        for (int j = 1; j <= cnt; j++) {
            int tp = prim[j];
            if (i * tp > N) break;
            vis[i * tp] = true;
            if (i % tp == 0) {
                phi[i * tp] = phi[i] * tp; break;
            }
            else phi[i * tp] = phi[i] * phi[tp];
        }
    }
    s[1] = phi[1];
    for (int i = 2; i < N; i++)
        s[i] = s[i - 1] + 2 * phi[i];
}
int main() {
    int n;
    init();
    while (cin >> n) {
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
            ans = (ans + s[n / i] * i % p * i % p) % p;
        cout << ans << endl;
    }
    return 0;
}
```