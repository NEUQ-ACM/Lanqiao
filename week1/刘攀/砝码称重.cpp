#include<bits/stdc++.h>
using namespace std;
int a[110];
int dp[105][200005];
int main(){
	int n;
	cin>>n;
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			if(!dp[i][j]){
				if(j==a[i]) dp[i][j]=1;
				if(dp[i-1][j+a[i]]) dp[i][j]=1;
				if(dp[i-1][abs(j-a[i])]) dp[i][j]=1;
			}
		}
	}
	long long ans=0;
	for(int j=1;j<=sum;j++){
		if(dp[n][j]) ans++;
	}
	cout<<ans<<endl;
}
