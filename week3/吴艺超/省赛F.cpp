#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1100000];
int n,x=1,sum,ans=1,tmp=-100005;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(x)
	{
		x++;
		int floor=pow(2,x)-1;
		if(floor>=n)
		{
			break;
		}
	}
	for(int i=1;i<=x;i++)
	{
		int k=pow(2,i-1);
		for(int j=k;j<k+k;j++)
		{
			sum+=a[j];
		}
		if(sum>tmp)
		{
			tmp=sum;
			ans=i;
		}
		sum=0;
	}
	cout<<ans;
}

