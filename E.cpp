#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int r=2;

    for(int i=1;i<20;i++){
        r=r+2*i;
    }

    int s=r+40;

    for(int i=2;i<=20;i++){
        s=s+40+i;
    }

    cout<<s;

    return 0;
}

