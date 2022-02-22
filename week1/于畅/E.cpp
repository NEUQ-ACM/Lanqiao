#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

//bool e[21][21];
//LL dp[1<<21][21];

int main()
{
    /*memset(e,0,sizeof(e));
    memset(dp,0,sizeof(dp));

    for(int i=0;i<21;i++)
        for(int j=i+1;j<21;j++)
            if(__gcd(i+1,j+1)==1) e[i][j]=e[j][i]=1;

    dp[1][0]=1;

    for(int s=0;s<(1<<21);s++){
        for(int j=0;j<21;j++){
            if(s>>j&1) for(int k=0;k<21;k++){
                if((s-(1<<j)>>k&1)&&e[k][j])
                    dp[s][j]+=dp[s-(1<<j)][k];
            }
        }
    }

    LL ans=0;

    for(int j=1;j<21;j++)
        ans+=dp[(1<<21)-1][j];

    cout<<ans;*/
    
    cout<<881012367360;

    return 0;
}
