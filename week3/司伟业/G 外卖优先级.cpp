#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
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
struct node{
	int t,i;
}g[maxn];
int f[maxn],lt[maxn],ans,s[maxn];
bool cmp(node a,node b)
{
	return a.t<b.t;
}
int main()
{
	int n=read(),m=read(),t=read();
	for(int i=1;i<=m;i++)
	{
		g[i].t=read();
		g[i].i=read();
	}
	sort(g+1,g+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
//		cout<<g[i].t<<" "<<g[i].i<<endl;
		if(g[i].t>t) break;
		f[g[i].i]-=max(0,g[i].t-lt[g[i].i]-1);
		lt[g[i].i]=g[i].t;
		if(f[g[i].i]<0) f[g[i].i]=0;
		if(f[g[i].i]<=3) s[g[i].i]=0;
		f[g[i].i]+=2;
		if(f[g[i].i]>5) s[g[i].i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]-=max(0,t-lt[i]);
		if(f[i]<0) f[i]=0;
		if(f[i]<=3) s[i]=0;
//		cout<<f[i]<<" ";
	}
	for(int i=1;i<=n;i++)
	if(s[i]) ans++;
	cout<<ans;
	return 0;
}
