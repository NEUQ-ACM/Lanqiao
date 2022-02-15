#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=(1<<21);
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
bool judge(int x,int y){
	if(gcd(x,y)==1) return true;
	return false;
}
int maps[30][30];
ll dp[maxn][30];
int main(){
	for(int i=1;i<=21;i++){
		for(int j=1;j<=21;j++){
			if(judge(i,j)){
				maps[i][j]=1;
			}
		}
	}
	ll num=(1<<21)-1;//最多是所有点都走过的情况 
	dp[1][1]=1;//经过1到达1的方案数为1 
	for(int i=1;i<=num;i++){//i的二进制表示有没有到达过某个点二进制位为1表示到达过，为0表示没到达过 
		for(int j=1;j<=21;j++){
			if((i>>(j-1)&1)){//j位到达过，即能到达j位 
				int q=i-(1<<(j-1)); //把到j位的情况删去求到达j的方法有多少种 
				for(int k=1;k<=21;k++){
					if(maps[k][j]==1&&((q>>(k-1))&1)==1){//K到j有路可走并且到达过k 
						dp[i][j]+=dp[q][k];
					}
				}
			} 
		}
	}
	ll ans=0;
	for(int i=1;i<=21;i++){
		ans+=dp[(1<<21)-1][i];//求所有的都到过的情况有多少种 
	}
	cout<<ans<<endl; 
}
