#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a[150], temp, k = -1, lit, m = 0, n = 0;
    memset(a, 0, sizeof(a));
    cin >> lit;
    while (cin >> temp)
    {
        a[temp % 100]++;
    }
    lit = temp / 100;
    bool flag = 1;
    for (int i = 0; i < 100; ++i)
    {
        if (a[i] == 0 && flag)
            continue;
        else
        {
            flag = 0;
        }
        if (a[i] == 0 && m == 0)
        {
            m = i + lit * 100;
        }
        else if (a[i] > 1)
        {
            n = i + lit * 100;
        }
    }
    cout << m << " " << n;
    return 0;
}