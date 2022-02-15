#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,ans=0;
	n=2021041820210418;
	for(long long i=1;i*i*i<=n;i++)
	if(n%i==0)
	for(long long j=i;j*j*i<=n;j++)
	if(n/i%j==0)
	{
		long long k=n/i/j;
		if(i==j&&i==k) ans++;
		else if(i==j||i==k||j==k) ans+=3;
		else ans+=6;
	}
	cout<<ans;
	return 0;
} 
