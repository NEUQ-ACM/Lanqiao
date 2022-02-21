#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
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
struct node{
	int val,c;
};
struct edge{
	int next,to,dis;
}g[maxn];
int a[maxn],num,last[maxn],d[maxn],vis[maxn];

bool operator<(node a,node b){return a.val>b.val;}
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int lcm(int a,int b){return a*b/gcd(a,b);}
priority_queue<node>q;

void add(int from,int to,int dis)
{
	g[++num].next=last[from];
	g[num].to=to;
	g[num].dis=dis;
	last[from]=num;
}

void dj()
{
	memset(d,0x3f,sizeof(d));
	d[1]=0;q.push((node){0,1});
	while(q.size())
	{
		node u=q.top();q.pop();
		if(vis[u.c]) continue;
		vis[u.c]=1;
		for(int i=last[u.c];i;i=g[i].next)
		{
			int v=g[i].to;
			if(d[v]>d[u.c]+g[i].dis)
			{
				d[v]=d[u.c]+g[i].dis;
				q.push((node){d[v],v});
			}
		}
	}
}

signed main()
{
	for(int i=1;i<=2021;i++)
	for(int j=i+1;j<=2021;j++)
	{
		if(j-i<=21){
			add(i,j,lcm(i,j));
			add(j,i,lcm(i,j));
		}
	}
	dj();
	printf("%lld",d[2021]);
	return 0;
}