#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],fa[100001],last[100001];
bool vis[100001];
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	int y=fa[x];
	int grandfa=find(fa[x]);	 
	last[grandfa]=max(last[y],last[x]);
	return fa[x]=grandfa;
}
void join(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
	{
		return;
	}
	fa[fy]=fx;
	last[fx]=max(last[fx],last[fy]);
}
int main()
{
	int n,x,fx,Max=-1000000;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		Max=max(Max,a[i]);
	}
	for(int i=0;i<=Max+n;i++)
	{
		fa[i]=i;
		last[i]=i;
	}
	for(int i=1;i<=n;++i)
	{
		x=a[i];
		if(vis[x])
		{
			x=last[find(x)]+1;
		}
		a[i]=x;
		vis[a[i]]=true;
		if(vis[x+1])
		{
			join(x,x+1);
		} 
		if(vis[x-1])
		{
			join(x-1,x);
		}
	} 
	cout<<a[1];
	for(int i=2;i<=n;++i)
	{
		cout<<" "<<a[i];
	}		
	return 0;	
}
