#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int w[maxn],n,dp[110][maxn+5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>w[i];
	}
	sort(w+1,w+1+n);
	for (int i=1;i<=n;i++){
		dp[i][w[i]]=1;
		for (int j=maxn;j>=1;j--){
			if (dp[i-1][j]){
				dp[i][j]=1;
				dp[i][j+w[i]]=1;
				dp[i][abs(w[i]-j)]=1;
			}
		}
	}
	int ans=0;
	for (int i=1;i<=100000;i++) if (dp[n][i]) ans++;
	cout<<ans;
	return 0;
} 
