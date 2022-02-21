#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int ans=0;

    for(int i=1;i<=2020;i++){
        for(int j=i+1;j<=2020;j++){
            if(__gcd(i,j)==1) ans++;
        }
    }

    cout<<ans*2+1;

    return 0;
}

