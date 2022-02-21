/*状压 dp[i][j]=x
表示现在在i这个点，现在所有点的状态是x，方案数是x
转移方程看代码吧 
答案是881012367360*/ 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=21;
const int maxs=1<<maxn;
using namespace std;
const int N=21;
int dp[maxn][maxs+100];
int g[maxn+5][maxn+5];
int gcd(int a, int b) { return b?gcd(b,a%b):a; } 
int dfs(int state,int pos){
    if(dp[pos][state]!=-1) return dp[pos][state];
    int res=0;
    for(int i=1;i<N;i++){
        if(((state>>i)&1)==0)continue;
        if(g[i][pos]==1){
            dp[i][state-(1<<pos)]=dfs(state-(1<<pos),i);
            res+=dp[i][state-(1<<pos)];
        }
    }
    dp[pos][state]=res;
    return res;
}
signed main() {
    memset(dp,-1,sizeof dp);
    for(int i=1;i<=N;i++)
        for(int j=i;j<=N;j++)
            if(gcd(i,j)==1)
				g[i-1][j-1] = g[j-1][i-1] = 1;
    for(int i=1;i<N;i++) dp[i][(1<<i)+1]=1;
    int sum=0;
    for(int i=1;i<N;i++){
    	dp[i][(1<<N)-1] = dfs((1<<N)-1,i);
        sum += dp[i][(1<<N)-1];
    }
    cout<<sum<<endl;
    return 0;
}


