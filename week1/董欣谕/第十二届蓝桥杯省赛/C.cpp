#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
const int maxn=1e7+6;
vector<int>a;
int cnt[maxn];
ll n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	n=2021041820210418;
	for (ll i=2;i*i<=n;i++){
		if (n%i==0){
			int num=0;
			while (n%i==0) n/=i,a.push_back(i),num++;
			cnt[i]+=num;
		}
	}
	if (n>1) a.push_back(n),cnt[n]+=1;
//	for (auto x:a) cout<<x<<"\n";
	cout<<2430;
	return 0;
} 
