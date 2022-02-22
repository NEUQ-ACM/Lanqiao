#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[105][25];
int f[(1<<20)+5];
int main(){
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k;j++){
		cin>>a[i][j];
	}
	int lim=1<<m;
	for(int i=1;i<=(1<<m)-1;i++){
		f[i]=-1;//可能达成i状态的方案数 
	}
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=1;j<=k;j++) t|=1<<a[i][j]-1;
		int nt;
		for(int st=0;st<lim;st++){
			if(f[st]==-1) continue;
			int nst=st|t;
			if(f[nst]==-1||f[nst]>f[st]+1) f[nst]=f[st]+1;
		}
	}
	cout<<f[(1<<m)-1];
}
