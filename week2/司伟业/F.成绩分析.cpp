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
int aa,Max,Min=1e9,tot;
int main()
{
	int n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		Max=max(Max,aa);
		Min=min(Min,aa);
		tot+=aa;
	}
	printf("%d\n%d\n%.2lf\n",Max,Min,double(tot*1.0/n));
	return 0;
}
