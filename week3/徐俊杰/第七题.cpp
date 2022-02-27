#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;

const int N = 100010;

int n, m, T;
int score[N], last[N];
bool st[N];
PII orders[N];

int main()
{
    scanf("%d%d%d", &n, &m, &T);
    for (int i = 0; i < m; i++) scanf("%d%d", &orders[i].x, &orders[i].y);
    sort(orders, orders + m);

    for (int i = 0; i < m; )
    {
        int j = i;
        while (j < m && orders[j] == orders[i]) j++;

        int id = orders[i].y, t = orders[i].x, cnt = j - i;
        i = j;

        score[id] -= t - last[id] - 1;
        score[id] = max(0, score[id]);
        if (score[id] <= 3) st[id] = false;
        score[id] += 2 * cnt;
        if (score[id] > 5) st[id] = true;

        last[id] = t;
    }

    for (int i = 1; i <= n; i++)
    {
        if (last[i] < T)
        {
            score[i] -= T - last[i];
            if (score[i] <= 3) st[i] = false;
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (st[i]) res++;

    printf("%d", res);

    return 0;
}
