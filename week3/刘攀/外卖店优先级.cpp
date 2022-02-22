#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000
typedef long long ll;
pair<int,int >order[maxn];
ll n,m,t;
int ans[maxn];
ll last[maxn];
bool first[maxn];
int main(){
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++){
		cin>>order[i].first>>order[i].second;
	}
	sort(order+1,order+1+m);
	for(int i=1;i<=m;i++){
		int ts=order[i].first;
		int id=order[i].second;
		if(ts!=last[id]){
			ans[id]=ans[id]-(ts-last[id]-1);
		}
		ans[id]=max(ans[id],0);
		if(ans[id]<=3){
			first[id]=false;
		}
		ans[id]+=2;
		if(ans[id]>5){
			first[id]=true;
		}
		last[id]=ts;
	}
	for(int i=1;i<=n;i++){
		if(last[i]!=t){
			ans[i]-=(t-last[i]);
			if(ans[i]<=3){
				first[i]=false;
			}
		}
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		if(first[i]) res++;
	}
	cout<<res<<endl;
}
