#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b)
    {
        d=a;
        x=1;
        y=0;
    }
    else
    {
        exgcd(b,a%b,d,y,x);
        y=y-x*(a/b);
    }
}

ll mul(ll a,ll b,ll mod)
{
    ll res=0;
    while(b)
    {
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res%mod;
}

ll pow(ll a,ll b,ll mod)
{
    ll res=1;
    while(b)
    {
        if(b&1) res=mul(res,a,mod);
        a=mul(a,a,mod)%mod;
        b>>=1;
    }
    return res%mod;
}

int main()
{
    ll n=1001733993063167141;
    // for(ll i=2;i<=sqrt(n);i++)
    //     while(n%i==0)
    //     {
    //         n=n/i;
    //         cout<<i<<" "<<n/i<<"\n";
    //     }
    ll p=891234941,q=1123984201;
    ll mod=(p-1)*(q-1);
    ll d=212353;
    ll e,y,gcd;
    exgcd(d,mod,gcd,e,y);
    e=(e%mod+mod)%mod;
    ll c=20190324;
    cout<<pow(c,e,n);
    return 0;
}
//579706994112328949