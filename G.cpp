#include<bits/stdc++.h>
using namespace std;
int n,m,a[N],num=0;
bool dp[N][M];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],m+=a[i];
    dp[0][0]=true;
    
    for (int i = 1; i <= n;i++)
        for (int j = 0; j <=m;j++)
            dp[i][j]=(dp[i-1][j]||dp[i-1][j+a[i]]||dp[i-1][abs(j-a[i])]);
    for(int i=1;i<=m;i++)
        if(dp[n][i])
            num++;
    cout<<num;
}

