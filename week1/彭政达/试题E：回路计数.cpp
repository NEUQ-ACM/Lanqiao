#include <bits/stdc++.h>
using namespace std;
typeedf long long ll; 
bool edge[30][30];
const int N=22,M=1<<21;
ll dp[M][30];
int gcd(int x, int y){
    if(!y) return x;
    else return gcd(y,x% y);
}
bool judge(int x, int y){
    if(gcd(x,y)==1) return true;
    else return false;
}
int main(){
    for(int i=1;i<N;i++)
        for(int j=1;j<N;j++)
            if(judge(i,j))
                edge[i][j]=1;
    dp[1][1]=1;
    for(int i=1;i<M;i++)
        for(int j=1;j<N;j++)
            if(i>>(j-1) & 1)
                for(int k=1;k<N;k++)
                    if(edge[k][j] && (i-(1<<(j-1)))>>(k-1) & 1)
                        dp[i][j]+=dp[(i-(1<<(j-1)))][k];
    ll ans=0;
    for (int i=2;i<N;i++) ans+=dp[M-1][i];
    cout<<ans;
    return 0;
}
