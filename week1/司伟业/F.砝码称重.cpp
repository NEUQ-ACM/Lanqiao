#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ooo 100000
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

int f[2][maxn],ans,a[maxn];
int main()
{
	int n;
	n=read();
	f[0][ooo]=1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		for(int j=0;j<=ooo*2;j++)
		{
			if(f[(i-1)%2][j])
			{
				f[i%2][j]=1;
				f[i%2][j+a[i]]=1;
				f[i%2][j-a[i]]=1;
//				cout<<j-ooo<<endl;
			}
		}
	}
	for(int i=ooo+1;i<=2*ooo;i++)
	{
		ans+=(bool)(f[n%2][i]);
	}
	
	cout<<ans;
	return 0;
}
