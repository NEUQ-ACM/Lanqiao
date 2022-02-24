#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
vector<int>g[maxn];
int dfs(int u){
	int len=g[u].size();
	int res=len;
	int maxn=0;
	for(int i=0;i<len;i++){
		maxn=max(maxn,dfs(g[u][i]));
	}
	res+=maxn;
	return res;
}
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		g[a].push_back(i);
	}
	int ans=dfs(1);
	cout<<ans<<endl;
}
