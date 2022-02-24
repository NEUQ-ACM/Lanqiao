#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll>v;
int main(){
	ll n=2021041820210418;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			v.push_back(i);
		if(n/i!=i) v.push_back(n/i);
	}}
	ll ans=0;
	for(auto a=v.begin();a!=v.end();a++)
	for(auto b=v.begin();b!=v.end();b++)
	for(auto c=v.begin();c!=v.end();c++)
	if(*a*(*b)*(*c)==n) ans++;
	cout<<ans<<endl;
}