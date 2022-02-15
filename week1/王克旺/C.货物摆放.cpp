#include<bits/stdc++.h>
using namespace std;
long long l,w,h,v=2021041820210418,cnt=0,a[5000];
int main()
{	
	int count=0;
	for(long long i=1;i<=sqrt(v);i++)
	{
		if(v%i==0)
		{
			a[cnt]=i;
			cnt++;
			if(i!=v/i)
			{
				a[cnt]=v/i;
				cnt++;
			}
		}
	}
	for(long long i=0;i<cnt;i++)
	{
		for(long long j=0;j<cnt;j++)
		{
			for(long long k=0;k<cnt;k++)
			{
				if(a[i]*a[j]*a[k]==v)
				{
					count++;
				}
			}
		}
	}
	cout<<count;
	return 0;
}
