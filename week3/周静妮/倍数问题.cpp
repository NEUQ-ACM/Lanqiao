#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 100;
int n, k;
ll ans = 0;
ll a[N];
void dfs(int pos, ll cnt, int count) {
    if (count == 3) {
        if (cnt % k == 0) ans = max(ans, cnt);
        return;
    }
    if (pos == n + 1) return;

    dfs(pos + 1, cnt + a[pos], count + 1);
    dfs(pos + 1, cnt, count);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1, 0, 0);
    cout << ans << "\n";
    return 0;
}
