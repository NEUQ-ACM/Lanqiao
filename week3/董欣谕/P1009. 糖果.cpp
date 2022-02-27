#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=21;
int dp[1<<N],a[110],vis[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		int cur=0;
		for (int j=1;j<=k;j++){
			int x;
			cin>>x;
			vis[x]=1;
			cur|=1<<(x-1);
		}
		a[i]=cur;
	}
	int flag=1;
	for (int i=1;i<=m;i++)
		if (!vis[i]) flag=0;
	if (!flag){
		cout<<-1;
		return 0;
	}
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for (int i=1;i<=n;i++){
		for (int j=(1<<m)-1;j>=0;j--){
			dp[j|a[i]]=min(dp[j|a[i]],dp[j]+1);
		}
	}
	cout<<dp[(1<<m)-1];
	return 0;
} 
