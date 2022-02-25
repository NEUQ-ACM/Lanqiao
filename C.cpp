#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int ans=1;

    for(int i=1;i<20;i++){
        ans+=4*i;
    }

    cout<<ans;

    return 0;
}

