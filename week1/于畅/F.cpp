#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int w[202];
bool dp[102][100002];

int main()
{
    int n,sum=0;

    memset(w,0,sizeof(w));
    memset(dp,0,sizeof(dp));

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>w[i];
        sum+=w[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(!dp[i][j]){
                if(w[i]==j) dp[i][j]=1;
                else if(dp[i-1][j+w[i]]) dp[i][j]=1;
                else if(dp[i-1][abs(j-w[i])]) dp[i][j]=1;
            }
        }
    }

    int ans=0;

    for(int j=1;j<=sum;j++)
        if(dp[n][j]) ans++;

    cout<<ans<<endl;

    return 0;
}
