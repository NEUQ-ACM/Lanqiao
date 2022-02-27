#include<iostream>
using namespace std;
#define ll long long
ll a[100096];
ll n;
int main()
{
    cin >> n;
    for (ll i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ll cs = 1;
    ll maxx = a[1];
    ll jg = 1;
    ll num = 1;
    ll p = 2;
    while (true)
    {
        cs++;
        num *= 2;
        ll sum = 0;
        for (ll j = p; j <= min(p + num - 1, n); j++)
            sum += a[j];
        if (sum > maxx)
        {
            jg= cs;
            maxx = sum;
        }
        p += num;
        if (p > n)
            break;
    }
    cout << jg << endl;
    return 0;
}