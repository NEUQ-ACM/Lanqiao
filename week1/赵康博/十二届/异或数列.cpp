#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int inf=0x3f3f3f3f;
const int maxn=1e5+5;
const int N=6e6+5;
const LL mod=998244353;
const double pi=acos(-1);
int cnt[30],bit[30],n,t,x;
int solve()
{
    for(int i=25;i>=0;i--)
        if(cnt[i]%2)
            return 0*printf("1\n");
    return 0*printf("0\n");
}
int main()
{
    scanf("%d",&t);
    for(int i=0;i<=25;i++) bit[i]=1<<i;
    while(t--)
    {
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            for(int i=25;i>=0;i--)
                if(x>=bit[i])
                    x-=bit[i],cnt[i]++;
        }
        solve();
    }
    return 0;
}

