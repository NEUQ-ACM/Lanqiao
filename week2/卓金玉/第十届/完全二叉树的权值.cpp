#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100005];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxLayer = 1, maxn = -1, k = 0;
    for (int i = 1; i <= log2(n + 1); i++)
    {
        int temp = 0;
        for (int j = 0; j < pow(2, i - 1); j++)
            temp += a[k++];
        if (temp > maxn)
        {
            maxn = temp;
            maxLayer = i;
        }
    }
    cout << maxLayer;
    return 0;
}
