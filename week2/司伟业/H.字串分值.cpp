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
#define int long long
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
char a[maxn];
int f[maxn],ans,l[maxn],r[maxn];
signed main()
{
	cin>>(a+1);
	int len=strlen(a+1);
	for(int i=1;i<=len;i++)
	{
		l[i]=f[a[i]-'a'];
		r[f[a[i]-'a']]=i;
		f[a[i]-'a']=i;
	}
	for(int i=1;i<=len;i++)
	{
		if(r[i]==0) r[i]=len+1;
		ans+=(r[i]-i)*(i-l[i]);
	}
	cout<<ans;
	return 0;
}
