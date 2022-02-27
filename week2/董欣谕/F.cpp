#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	double tot=0;
	int Max=-1,Min=INF;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		Max=max(Max,x);
		Min=min(Min,x);
		tot+=x;
	}
	cout<<Max<<'\n'<<Min<<'\n'<<fixed<<setprecision(2)<<tot/n;
	return 0;
} 
