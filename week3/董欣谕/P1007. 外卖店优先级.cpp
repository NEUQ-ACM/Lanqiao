#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=1e5+5;
struct node{
	int t,id;
	bool operator < (const node &o) const{
		if(id!=o.id)return id<o.id;
		return t<o.t;
	}
}p[N];
int vis[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,t;
	cin>>n>>m>>t;
	for (int i=1;i<=m;i++)
		cin>>p[i].t>>p[i].id;
	sort(p+1,p+1+m);
	int last=1,ans=0;
	for (int i=1;i<=n;i++){
		int cur=0,time=0;
		while (last<=m&&p[last].id==i) {
			cur=max(0,cur-max(0,p[last].t-time-1));
			if (cur<=3) vis[i]=0;
			cur+=2;
			if (cur>5) vis[i]=1;
			time=p[last].t;
			last++;
		}
		cur=max(0,cur-(t-time));
		if (cur<=3) vis[i]=0;
	}
	for (int i=1;i<=n;i++)
		if (vis[i]) ans++;
	cout<<ans;
	return 0;
} 
