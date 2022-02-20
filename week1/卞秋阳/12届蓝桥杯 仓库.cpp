#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans; 
ll n=2021041820210418;
int main()
{
	for(ll i=1;i*i*i<=n;i++)
	{
		if(n%i!=0)continue;
		ll tmp=n/i;
		for(ll j=1;j*j<=tmp;j++)
		{
			if(tmp%j!=0) continue;
			ll k=tmp/j;
			if(k<j || i>j) continue;
			if(i==j&&i==k) ans++;
			else if(i==j||i==k||j==k)ans+=3;
			else ans+=6;
		}
	} 
	cout<<ans;
}
