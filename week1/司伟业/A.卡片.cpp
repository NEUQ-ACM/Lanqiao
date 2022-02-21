#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define int long long
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}
int a[maxn];
int cal(int x)
{
	int cnt=0;
	for(register int i=1;i*i<=x;i++)
	{
		if(x%i) continue;
		if(i*i==x) cnt++;
		else cnt+=2; 
	}
	return cnt;
}

signed main()
{
	int n=read(),ans=0;
	for(register int i=1;i*i<=n;i++)
	{
		if(n%i) continue;
		if(i*i==n) ans+=cal(i);
		else {
			ans+=cal(i);
			ans+=cal(n/i);
		}
	}
	cout<<ans;
}