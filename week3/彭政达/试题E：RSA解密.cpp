#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm=1e8+10;
const ll n=1001733993063167141ll;
const ll p=891234941ll;
const ll q=1123984201ll;
const ll d=212353;
const ll c=20190324;
int a[maxm],sushu[maxm/10],cnt;
bool notPrime[maxm]; 
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
	if(b==0){
		d=a,x=1,y=0;
		return;
	}
	exgcd(b,a%b,d,y,x);
	y-=(a/b)*x;
}
ll rev(ll t,ll m){
	ll d,x,y;
	exgcd(t,m,d,x,y);
	return (x%m+m)%m;
}
ll fast_product(ll a,ll b,ll mod){
	ll ans=0;
	while(b){
		if(b&1) ans=(ans+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return ans;
} 
ll fast_pow(ll a,ll b,ll mod){
	ll ans=1;
	while(b){
		if(b&1) ans=fast_product(ans,a,mod);
		a=fast_product(a,a,mod);
		b>>=1;		
	} 
	return ans;
}
int main(){
	ll y=(p-1)*(q-1);
	ll e=rev(d,y);
	ll answer=fast_pow(c,e,n);
	cout<<answer<<endl;
	return 0;
}
