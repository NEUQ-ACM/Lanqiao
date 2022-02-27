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

int n,m,k,f[maxn<<2],t[maxn];
int main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
	for(int j=1;j<=k;j++)
	{
		int aa=read();
		t[i]|=1<<(aa-1);
	}
	memset(f,0x3f,sizeof(f));f[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=(1<<m)-1;j++)
		f[j|t[i]]=min(f[j|t[i]],f[j]+1);
	}
	if(f[(1<<m)-1]>=1e9) cout<<-1;
	else cout<<f[(1<<m)-1];
	return 0;
}
