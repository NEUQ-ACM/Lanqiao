#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n, f[maxn], a[maxn];
int find(int x)
{
    if (x == f[x])
    {
        return f[x];
    }
    else
    {
        return f[x] = find(f[x]);
    }
}
void merge(int x, int y)
{
    int findx = find(x);
    int findy = find(y);
    if (findx == findy)
    {
        return;
    }
    else if (findx < findy)
    {
        f[findx] = findy;
    }
    else
    {
        f[findy] = findx;
    }
    return;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int re = find(a[i]);
        merge(re, re + 1);
        if (i == 1)
        {
            cout << re;
        }
        else
        {
            cout << " " << re;
        }
    }
    cout << endl;
    return 0;
}
