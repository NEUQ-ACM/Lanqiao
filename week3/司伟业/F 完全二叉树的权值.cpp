#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#define int long long
#define clean(x) memset(x,0,sizeof(x))
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
int maxx=-2e18,ans,t=1,cnt,tot,de;
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int aa=read();
		++cnt;tot+=aa;
		if(cnt==t) {
			de++;
			t=t*2,cnt=0;
			if(tot>maxx) {
				maxx=tot;
				ans=de;
			}
			tot=0;
		}
	}
	if(tot>maxx) ans=++de;
	cout<<ans;
}
