#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int fa[10],vis[10];
struct edge{
	int u,v;
}ed[7]={{1,2},{1,3},{2,4},{3,5},{3,4},{4,6},{5,6}};
int find(int x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[xx]=yy;
}
bool judge(vector<int>a){
	memset(vis,0,sizeof vis);
	for (int i=1;i<=6;i++) fa[i]=i;	
	for (int i=0;i<(int)a.size();i++)
		if (a[i]&&find(ed[i].u)!=find(ed[i].v)) {
			merge(ed[i].u,ed[i].v);
			vis[ed[i].u]=1;
			vis[ed[i].v]=1;
		}
	int cnt=0;
	for (int i=1;i<=6;i++)
		if (vis[i]&&fa[i]==i) cnt++;
	return cnt<=1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int ans=0;
	for (int i=1;i<(1<<7);i++){
		vector<int>a;
		int temp=i;
		while (temp){
			a.push_back(temp&1);
			temp>>=1;
		}
		if (judge(a)) ans++;
	}
	cout<<ans;
	return 0;
} 
