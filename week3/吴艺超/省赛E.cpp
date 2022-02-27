#include<bits/stdc++.h>
#define int long long
using namespace std;
int p=891234941,q=1123984201,n=1001733993063167141,d=212353,c=20190324;
int y=(p-1)*(q-1);
//void getpq(int x)
//{
//	for(int i=1e8+1;i<x;i+=2)
//	{
//		if(x%i==0)
//		{
//			p=i;x/=i;
//		}
//	}
//	q=x;
//	cout<<p<<" "<<q;
//}±©Á¦µÃµ½p=891234941 q=1123984201£»
void exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;y=0;
		return;
	}
	exgcd(b,a%b,y,x);
	y-=(a/b)*x;
}
int rev(int t,int m)
{
	int x,y;
	exgcd(t,m,x,y);
	return (x%m+m)%m;
}
int ksc(int a,int b,int p)
{
	int ans=0;
	while(b)
	{
		if(b&1)ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
}
int ksm(int x,int y,int p)
{
	int res=1;
	for(;y;y>>=1,x=ksc(x,x,p))
		if(y&1)res=ksc(res,x,p);
	return res;
}
signed main()
{
	//getpq(1001733993063167141);
	int e=rev(d,y);
	int ans=ksm(c,e,n);
	cout<<ans;
}

