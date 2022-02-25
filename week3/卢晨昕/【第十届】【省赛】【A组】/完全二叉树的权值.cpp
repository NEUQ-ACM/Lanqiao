//100
#include<bits/stdc++.h>

using namespace std;
int n;
int a[100005];
int maxn;
int now=0;
int deep=2;
int ans;
bool pan(int a)
{
	while(a)
	{
		if(!(a&1))return false;
		a>>=1; 
	}
	return true;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	maxn=a[1];
	for(int i=2;i<=n;i++)
	{
		now+=a[i];
		if(pan(i)||i==n)
		{
			if(now>maxn)
			{
				maxn=now;
				ans=deep;
			}
			deep++;
			now=0;
		}
	}
	cout<<ans;
	return 0;
}
