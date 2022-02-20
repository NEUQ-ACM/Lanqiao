#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int ans=0;

    for(int i=1;i<=2020;i++){
        int x=i;
        while(x){
            if(x%10==2) ans++;
            x/=10;
        }
    }

    cout<<ans;

    return 0;
}

