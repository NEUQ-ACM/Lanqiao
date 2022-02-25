#include<bits/stdc++.h>
using namespace std;
int mp[2022][2022];
int Inf=0x3f3f3f3f;
int gcd(int a,int b)
{
	int m=max(a,b);
	int n=min(a,b);
	if(m%n==0)
	return n;
	else
	return gcd(m%n,n);
}
int main()
{
	int vis[2025]={};
	vis[1]=1;
	int dis[2025]={};
	memset(dis,0x3f,sizeof(dis));
	memset(mp,0x3f,sizeof(mp));
	for(int i=1;i<=2021;i++)
	mp[i][i]=0;
	for(int i=1;i<=2021;i++)
	{
		for(int j=i+1;j<=2021;j++)
		if(j-i<=21)
		{
			int k=i*j/gcd(i,j);
			mp[i][j]=k;
			mp[j][i]=k;
		}
	}
	for(int i=1;i<=2021;i++)
	if(mp[1][i]<Inf)
	dis[i]=mp[1][i];
	for(int i=1;i<=2021;i++)
	{
		int _min=Inf,x;
		for(int j=1;j<=2021;j++)
		{
			if(!vis[j]&&dis[j]<=_min)
			{
				x=j;
				_min=dis[j];
			}
		}
		vis[x]=1;
		for(int j=1;j<=2021;j++)
		if(!vis[j])
		dis[j]=min(dis[j],dis[x]+mp[x][j]);
	}
	cout<<dis[2021];
}
