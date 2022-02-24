#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int N=1e5+5,M=1e6+5;
int a[N],tr[M+N];
int n;
void add(int i,int x){
	while (i<M+N){
		tr[i]+=x;
		i+=i&-i;
	}
}
int query(int i){
	int ans=0;
	while (i){
		ans+=tr[i];
		i-=i&-i;
	}
	return ans;
}
int sum(int l,int r){
	return query(r)-query(l-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=n;i++){
		int l=a[i],r=M+N,cur=a[i];
		while (l<=r){
			int mid=(l+r)>>1;
			if (sum(l,mid)<mid-l+1){
				cur=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		add(cur,1);
		a[i]=cur;
	}
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
} 
