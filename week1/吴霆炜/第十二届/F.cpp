#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
#define ll long long

int a[110];
int dp[105][maxn];
int main(){
	int n;
	cin>>n;
	ll sum=0;
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
	ll res=0;
	for(int j=1;j<=sum;j++){
		if(dp[n][j]) res++;
	}
	cout<<res<<endl;
}