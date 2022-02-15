#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
long long tar = 2021041820210418;
vector<long long> a;
int main()
{
    long long remp = tar;
    for (int i = 1; i <= sqrt(remp); i++)
    {
        if (remp % i == 0)
        { 
            a.push_back(i);
            if (i * i != remp)
                a.push_back(remp / i);
        }
    }
    int len = a.size();
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++)
            for (int k = 0; k < len; k++)
                if (a[i] * a[j] * a[k] == tar)
                    ans++;
    cout << ans;
    return 0;
}