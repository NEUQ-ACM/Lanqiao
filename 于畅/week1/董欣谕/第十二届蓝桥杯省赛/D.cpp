#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=2050;
struct edge{
	int to,next,w;
}ed[maxn*maxn];
int head[maxn],vis[maxn],cnt=0;
ll dis[maxn];
void add(int u,int v,int w){
	ed[++cnt].to=v;
	ed[cnt].next=head[u];
	head[u]=cnt;
	ed[cnt].w=w;
}
void dij(){
	memset(dis,INF,sizeof dis);
	priority_queue<pii,vector<pii>,greater<pii>>q;
	dis[1]=0;
	q.push({dis[1],1});
	while (!q.empty()){
		int u=q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u]=1;
		for (int i=head[u];i;i=ed[i].next){
			int v=ed[i].to;
			if (dis[v]>dis[u]+ed[i].w){
				dis[v]=dis[u]+ed[i].w;
				q.push({dis[v],v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n=2021;
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=min(i+21,n);j++){
			int temp=i*j/__gcd(i,j);			
			add(i,j,temp);
			add(j,i,temp);
		}
	dij();
	cout<<dis[2021];
	return 0;
} 
