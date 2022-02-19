#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f;
ll dis[2050],e[2050][2050];
int vis[2050];
ll gcd(ll a,ll b)
{
	return a%b==0?b:gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/gcd(a,b);
}
int main()
{
	fill(dis,dis+2050,inf);
	fill(e[0],e[0]+2050*2050,inf);
	for(int i=1;i<=2021;i++)
	{
		for(int j=1;j<=21;j++)
		{
			int k=i+j;
			if(k<=2021){e[i][k]=lcm(i,k);e[k][i]=lcm(i,k);}
		}
	}
	dis[1]=0;
	for(int i=1;i<=2021;i++)
	{
		ll u=-1;
		ll minn=inf;
		for(int j=1;j<=2021;j++)
		{
			if(!vis[j]&&dis[j]<minn)
			{
				minn=dis[j];
				u=j;
			}
		}
		if(u==-1){break;}
		vis[u]=1;
		for(int v=1;v<=2021;v++)
		{
			if(!vis[v]){dis[v]=min(dis[v],e[u][v]+dis[u]);}
		}
	}
	cout<<dis[2021];
	return 0;
}
