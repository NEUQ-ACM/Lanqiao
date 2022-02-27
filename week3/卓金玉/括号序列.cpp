#include <bits/stdc++.h>
using namespace std;
#define N 5003
int f[N][N];
int mod = 1e9 + 7;
string s;
long long cal(int n)
{
    memset(f, 0, sizeof(f));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        if (s[i - 1] == '(')
            for (int j = 1; j <= n; j++)
                f[i][j] = f[i - 1][j - 1];
        else
        {
            f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mod;
            for (int j = 1; j <= n; j++)
                f[i][j] = (f[i - 1][j + 1] + f[i][j - 1]) % mod;
        }
    for (int i = 0; i <= n; i++)
        if (f[n][i])
            return f[n][i];
    return -1;
}
int main()
{
    int n;
    getline(cin, s);
    n = s.length();
    long long a = cal(n);
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++)
        if (s[i] == ')')
            s[i] = '(';
        else
            s[i] = ')';
    long long b = cal(n);
    cout << (a * b) % mod << endl;
}
