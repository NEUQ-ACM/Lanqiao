#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
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
int a[maxn];
int main()
{
	int t,n,pd;
	t=read();
	while(t--)
	{
		n=read();pd=0;
		for(int i=1;i<=n;i++)
		a[i]=read();
		for(int j=20;j>=0;j--)
		{
			int tot=0;
			for(int i=1;i<=n;i++)
				if(a[i]&(1<<j)) tot++;
			if(tot==1) {pd=1;break;}
			else if(tot%2==0) continue;
			else {
				if(n%2==1)
				{
					pd=1;
					break;
				}
				else 
				{
					pd=-1;
					break;
				}
			}
		}
		printf("%d\n",pd);
	}
	return 0;
}
// 7 992438 1006399 781139 985280 4729 872779 563580
