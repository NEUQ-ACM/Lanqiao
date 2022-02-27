#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int mod=1e9+7;
int t,k;
int n,m;
ll C(ll a,ll b)
{
	if(b==0)return 1;
	if(b==1)return a;
	if(b>a/2)
	{
		return C(a,a-b);
	}
	return C(a-1,b)+C(a-1,b-1);
}
int main()
{
	cin>>t>>k;
	while(t--)
	{
		ll ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,m);j++)
			{
				if(C(i,j)%k==0)ans++;
				ans%=mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
