#include <bits/stdc++.h>
using namespace std;
#define ll long long
int num = 0;
ll e,d=212353,n=1001733993063167141,C=20190324,p,q,remp;
ll q_pow(ll a, ll b, ll c) {
    a%=c;
    ll ans=1;
    while(b) {
        if(b&1) ans=ans*a%c;
        b>>=1;
        a=a*a%c;
    }
    return ans;
}
ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = ex_gcd(b, a % b, x, y);
    ll tmp = x;
    x = y;
    y = tmp - a / b * y;
    return d;
}
int main()
{
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            p = i, q = n % i;
    }
    ll sum = (p - 1) * (q - 1);
    ll x, y;
    e = ex_gcd(d, sum, x, y);
    e = (e % sum + sum) % sum;
    cout << q_pow(C, e, d);
    return 0;
}