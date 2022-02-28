#include<iostream>
#include<cstdio>
#define ll long long
#define P 1000000007
#define I2 500000004
using namespace std;
int T,k;ll n,m,f[70][2][2];
ll Get(ll x,ll y)
{
	if (x<0||y<0) return 0;
	if (x>y) return ((ll)(1+y+1)%P*((y+1)%P)%P*I2%P+(ll)(x-y)%P*((y+1)%P))%P;
	if (x<=y) return (ll)(1+x+1)%P*((x+1)%P)%P*I2%P;
}
int main()
{
	scanf("%d%d",&T,&k);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		if (m>n) m=n;
		ll Ans=Get(n,m);
		f[0][0][0]=1;
		int i=1;
		for (;n;i++,n/=k,m/=k)
		{
			ll x=n%k,y=m%k;
			
			f[i][0][0]=(f[i-1][0][0]*Get(x,y)%P+f[i-1][1][0]*Get(x-1,y)%P+f[i-1][0][1]*Get(x,y-1)%P+f[i-1][1][1]*Get(x-1,y-1)%P)%P;
			f[i][0][1]=(f[i-1][0][0]*Get(x,k-1)%P+f[i-1][1][0]*Get(x-1,k-1)%P+f[i-1][0][1]*Get(x,k-1)%P+f[i-1][1][1]*Get(x-1,k-1)%P-f[i][0][0])%P;
			f[i][1][0]=(f[i-1][0][0]*Get(k-1,y)%P+f[i-1][1][0]*Get(k-1,y)%P+f[i-1][0][1]*Get(k-1,y-1)%P+f[i-1][1][1]*Get(k-1,y-1)%P-f[i][0][0])%P;
			f[i][1][1]=(Get(k-1,k-1)*(f[i-1][0][0]+f[i-1][0][1]+f[i-1][1][0]+f[i-1][1][1])-f[i][0][0]-f[i][0][1]-f[i][1][0])%P;
		}
		printf("%lld\n",((Ans-f[i-1][0][0])%P+P)%P);
	}
}