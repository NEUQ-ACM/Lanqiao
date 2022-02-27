#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
typedef long long ll;
const int mod=1e9+7;
const ll INF=0x3f3f3f3f3f3f3f3f; 
ll a[100001],sum[100];
int getroot(int x){
	int cnt=0;
	while (x){
		cnt++;
		x/=2;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[getroot(i)]+=a[i];
	}
	ll ans=-INF,dep;
	for (int i=1;i<=100;i++)
		if (sum[i]>ans){
			dep=i;
			ans=sum[i];
		}
	cout<<dep;
	return 0;
} 