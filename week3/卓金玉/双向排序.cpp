#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v;
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        v.push_back(i);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (a)
        {
            sort(v.begin() + b - 1, v.end());
        }
        else
        {
            sort(v.begin(), v.begin() + b, cmp);
        }
    }
    vector<int>::iterator it = v.begin();
    for (it; it != v.end(); ++it)
    {
        if (it == v.begin())
            cout << *it;
        else
            cout << " " << *it;
    }
    cout << endl;
    return 0;
}