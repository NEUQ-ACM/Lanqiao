#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int n,m,k;
int s[105];//代表第i包糖果
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        int ss=0;
        int t;
        for(int j=0;j<k;j++)
        {
            scanf("%d",&t);
            ss|=(1<<(t-1));
        }
        s[i]=ss;
        dp[ss]=1;
    }
 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            if(dp[j]==-1)continue;
            if(dp[j|s[i]]==-1)dp[j|s[i]]=dp[j]+dp[s[i]];
            else dp[j|s[i]]=min(dp[j|s[i]],dp[j]+dp[s[i]]);
        }
    }
    printf("%d\n",dp[(1<<m)-1]);
    return 0;
}
