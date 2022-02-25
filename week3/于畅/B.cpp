#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int main()
{
    int a[4],x=3;

    a[0]=1;a[1]=1;a[2]=1;

    for(int i=0;i<20190321;i++){
        if(x==0) a[x]=a[1]+a[2]+a[3];
        else if(x==1) a[x]=a[0]+a[2]+a[3];
        else if(x==2) a[x]=a[0]+a[1]+a[3];
        else if(x==3) a[x]=a[0]+a[1]+a[2];
        a[x]%=10000;
        if(i==20190320) break;
        if(x==3) x=0;
        else x++;
    }

    cout<<a[x];

    return 0;
}

