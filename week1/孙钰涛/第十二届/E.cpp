#include<bits/stdc++.h>
using namespace std;
const int N = 22, M = 1 << N;
long long f[M][N];
bool edge[N][N];
int main()
{
    memset(edge,0,sizeof(edge));
    for(int i=1;i<=21;i++)
        for(int j=1;j<=21;j++)
            if(__gcd(i,j)==1) edge[i][j]=1;
    f[2][1]=1;
    for(int i=2;i<=M-2;i++)
        for(int j=1;j<=21;j++)
            if(i>>j&1)
                for(int k=1;k<=21;k++)
                    if(i-(1<<j)>>k&1&&edge[k][j])
                        f[i][j]=f[i][j]+f[i-(1<<j)][k];
    long long ans=0;
    for(int i=2;i<=21;i++)
        ans=ans+f[M-2][i];
    cout<<ans;
    return 0;
}
//881012367360