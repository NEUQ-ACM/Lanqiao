#include <iostream>
#include <cstring>
using namespace std;
const int N = 2e5 + 5;
long long w[N];
int n;
int cnt[25];

void op(long long x)
{
    int t = 0;
    while (x)
    {
        t++;
        if (x & 1)
            cnt[t]++;
        x >>= 1;
    }
}
void solve()
{
    memset(cnt, 0, sizeof cnt);
    int sum = 0;
    for (int i = 1; i <= n; i++)
        op(w[i]), sum ^= w[i];
    if (!sum)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 20; i > 0; i--)
    {
        if (cnt[i] == 1)
        {
            cout << 1 << endl;
            return;
        }
        if (cnt[i] & 1)
        {
            if (n & 1)
            {
                cout << 1 << endl;
                return;
            }
            else
            {
                cout << -1 << endl;
                break;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i];
        }
        solve();
    }
}
