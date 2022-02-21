#include<bits/stdc++.h>
using namespace std;
int a[16];
int dp[16][100005];
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][a[i]]=1;
		for(int j=1;j<=100000;j++){
			if(dp[i-1][j]){
				dp[i][j]=1;
				dp[i][j+a[i]]=1;
				dp[i][abs(a[i]-j)]=1;
			}
		}
	}
	for(int i=1;i<=100000;i++){
		if(dp[n][i])ans++;
	}
	cout<<ans;
	return 0;
} 
