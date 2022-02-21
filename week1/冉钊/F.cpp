#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int N;
int w[110];
bool dp[110][maxn];
int sum;
int ans;
int main(){
    ios::sync_with_stdio(false);//输入输出的速度优化
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>w[i];
        sum+=w[i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(w[i]==j){
                dp[i][j]=1;
            }else if(dp[i-1][j+w[i]]){
                dp[i][j]=1;
            }else if(dp[i-1][abs(j-w[i])]){
                dp[i][j]=1;
            }
        }
    }
    for(int i=1;i<=sum;i++){
        if(dp[N][i])ans++;
    }
    cout<<ans;

    return 0;
}