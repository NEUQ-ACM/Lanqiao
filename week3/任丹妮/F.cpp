#include <bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int a[101],dp[101][MAX]={0};
int main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	dp[1][a[1]]=1;
	for(int i=2;i<=n;i++){
		int x=a[i];
		for(int j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
		}
		dp[i][x]=1;
		for(int j=1;j<=sum;j++){
			if(dp[i-1][j]==1){
				dp[i][j+x]=1;
				dp[i][abs(j-x)]=1;
			}
		}
	}
	int ans=0;
		for(int j=1;j<=sum;j++){
			if(dp[n][j]==1) ans++;
		}
	cout<<ans<<endl;
} 
