#include<bits/stdc++.h>
using namespace std;
int a[100001],b[100001],ji[100001],last[100001];
bool vis[100001];
int find(int x)
{
	if(x==ji[x])
	{
		return x;
	}
	int y=ji[x];
	int grandji=find(ji[x]);	 
	last[grandji]=max(last[y],last[x]);
	return ji[x]=grandji;
}
void join(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
	{
		return;
	}
	ji[fy]=fx;
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
		ji[i]=i;
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