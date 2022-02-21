#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 0x7fffffff
ll rt[100000],a[100000];
int n,limit,num;
int main() {
    cin>>n>>a[1];
    rt[1]=a[1],num=2,limit=4;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        rt[num] += a[i];
        if (i + 1 == limit) {
            limit = limit * 2;
            num++;
        }
    }
    ll ans = 0,max1 = -INF;
    for (int i = 1; i <= num; i++)
        if (max1 <= rt[i])
            max1 = rt[i], ans = i;
    cout << ans;
    return 0;
}