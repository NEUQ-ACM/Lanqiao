#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#define clean(x) memset(x,0,sizeof(x))
#define maxn 2000005
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
int a[maxn],f[maxn];
int fi(int x)
{
	if(x!=f[x]) f[x]=fi(f[x]);
	return f[x];
}
int main()
{
	int n=read();
	for(int i=1;i<=2e6;i++) f[i]=i;
	for(int i=1;i<=n;i++)
	{
		int aa=read();
		if(aa==f[aa]) {
			a[i]=aa;
			f[aa]=fi(aa+1);
		}
		else{
			a[i]=fi(aa);
			f[fi(aa)]=fi(fi(aa)+1);
		}
	}
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}
