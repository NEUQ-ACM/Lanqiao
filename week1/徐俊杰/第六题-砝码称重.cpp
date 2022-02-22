#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int offset = 100052;
const int maxn = 100052 + offset;
int n, vis[2][maxn], a[2000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    memset(vis, 0, sizeof(vis));
    vis[0][offset] = 1;
    int pre = 0, cur = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < maxn; j++) {
            vis[cur][j] = max(vis[cur][j], vis[pre][j]);
            if (j - a[i] >= 0) {
                vis[cur][j] = max(vis[pre][j - a[i]], vis[cur][j]);
            }
            if (j + a[i] < maxn) {
                vis[cur][j] = max(vis[pre][j + a[i]], vis[cur][j]);
            }
        }
        swap(pre, cur);
    }

    int ans = 0;
    for (int i = offset + 1; i < maxn; i++) {
        if (vis[pre][i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
