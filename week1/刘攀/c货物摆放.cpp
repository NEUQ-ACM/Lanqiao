#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll>v;
int main(){
	ll n=2021041820210418;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			v.push_back(i);
			if(n/i!=i){
				v.push_back(n/i);
			}
		}
	}
	ll sum=0;
	for(vector<ll>::iterator a=v.begin();a!=v.end();a++)
	for(vector<ll>::iterator b=v.begin();b!=v.end();b++)
	for(vector<ll>::iterator c=v.begin();c!=v.end();c++)
	if(*a*(*b)*(*c)==n) sum++;
	cout<<sum<<endl;
}
