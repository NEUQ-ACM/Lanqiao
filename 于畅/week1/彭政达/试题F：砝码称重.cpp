#include <bits/stdc++.h>
using namespace std;
const int N=110,M=2e5+10;
int sum,n,w[N];
bool flag[N][M];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        sum+=w[i];
    }
    flag[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=sum;j++)
            flag[i][j]=f[i-1][j] || flag[i-1][j+w[i]] || flag[i-1][abs(j-w[i])];
    int ans=0;
    for(int i=1;i<=sum;i++)
        if(flag[n][i]) ans++;
    cout<<ans;
    return 0;
}
