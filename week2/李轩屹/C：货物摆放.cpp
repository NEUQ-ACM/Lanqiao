#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main(){
    ll n =  2021041820210418L;
    ll ans = 0;
    for(ll i = 1;i*i*i <=n;i++){
        if(n%i != 0) continue;	//若是i不是n的因子，就continue。
        ll tmp = n / i;
        for(ll j = 1;j*j<= tmp;j++){
            if(tmp % j != 0) continue;//若j不是(n/i)的因子，就continue。
            ll k = tmp / j;
            if(k < j || i > j)  continue;//如果三个数不是递增，就continue，去重
            if(i == j && i == k) ans +=1;
            else if(i == j || i==k || j==k) ans +=3;
            else ans += 6;
        }
    }
    cout<< ans <<endl;
    return 0;
}

