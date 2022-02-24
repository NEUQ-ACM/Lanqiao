#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=2e3+5;
int c[N][N],sum[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t,k;
	cin>>t>>k;
	c[0][0]=1;
	c[1][0]=1,c[1][1]=1;
	for (int i=2;i<N;i++){
		for (int j=0;j<=i;j++){
			if (j==0) c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=k;
		}
	}
	for (int i=1;i<N;i++){
		for (int j=1;j<=i;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if (c[i][j]==0) sum[i][j]++;
		}
		sum[i][i+1]=sum[i][i];
	}
	while (t--){
		int n,m;
		cin>>n>>m;
		if (m>n) m=n;
		cout<<sum[n][m]<<'\n';
	}
	return 0;
} 
