#include<vector>
#include<set>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>
using namespace std;

const int maxn = 2021 + 5, INF = 0x3f3f3f3f;
long w[maxn][maxn], v[maxn]/*临时标记是否查询过*/, d[maxn]/*到节点的路径*/;
int n=2022;

void Dijkstra(int k) {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= 2021; i++) d[i] = (i == k ? 0 : INF);
    for (int i = 1; i <= 2021; i++) {
        int x{}, m = INF;
        for (int y = 0; y < n; y++) if (!v[y] && d[y] <= m) m = d[x = y];
        v[x] = 1;
        for (int y = 0; y < n; y++) d[y] = min(d[y], d[x] + w[x][y]);
    }
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    memset(w, INF, sizeof(w));
    for (size_t i = 1; i <= 2021; i++)
    {
        for (size_t j = i+1; j <= 2021; j++)
        {
            if (j - i > 21)break;
            w[i][j] = i * j / gcd(i, j);
            w[j][i] = i * j / gcd(i, j);
        }
    }
    Dijkstra(1);
    cout << d[2021] << endl;
}