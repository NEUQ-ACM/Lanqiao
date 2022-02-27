#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e5+4;
vector<int>g[maxn];
int f[maxn];
void dfs(int x,int last){
	int Max=0;
	for (int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if (v!=last){
			dfs(v,x);
			Max=max(Max,f[v]);
		}
	}
	f[x]=g[x].size()+Max;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=2;i<=n;i++){
		int x;
		cin>>x;
		g[x].push_back(i);
	}
	dfs(1,0);
	cout<<f[1];
	return 0;
} 