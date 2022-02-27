#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

LL n=1001733993063167141;
LL d=212353,c=20190324;
LL p=891234941,q=1123984201,m=1001733991047948000;

LL exgcd(LL a,LL b,LL& x,LL &y)
{
    if(!b){
        x=1;
        y=0;
        return a;
    }
    LL gcd=exgcd(b,a%b,x,y);
    LL temp=x;
    x=y;
    y=temp-(a/b)*y;
    return gcd;
}

LL q_m(LL a,LL b,LL n)
{
    LL ans=0;
    while(b){
        if(b&1) ans=(ans+a)%n;
        a=(a*2)%n;
        b>>=1;
    }
    return ans;
}

int main()
{
    /*
    bool flag=0;
    for(int i=2;i<=sqrt(n);i++){
        while(!(n%i)){
            cout<<i<<' '<<n/i;
            flag=1;
            break;
        }
        if(flag) break;
    }
    p=891234941; q=1123984201;
    LL m=(p-1)*(q-1);
    cout<<m;
    m=1001733991047948000;
    */

    LL gcd,x,y,e;
    gcd=exgcd(d,m,x,y);
    if(gcd==1) e=(x%m+m)%m;
    else return -1;

    LL ans=1;
    while(e){
        if(e&1) ans=q_m(c,ans,n)%n;
        e>>=1;
        c=q_m(c,c,n)%n;
    }

    cout<<ans;

    return 0;
}

