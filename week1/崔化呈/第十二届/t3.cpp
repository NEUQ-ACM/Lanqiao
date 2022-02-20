#include<bits/stdc++.h>
using namespace std;
const long long M=2021041820210418;
int main()
{
	vector<long long>f;
	for(long long i=1;i<=sqrt(M);i++)
	{
		if(M%i==0)
		{
			f.push_back(i);
			f.push_back(M/i);
		}
	}
	long long len=f.size();
	long long ans=0;
	for(long long i=0;i<len;i++)
	{
		for(long long j=0;j<len;j++)
		{
			if(M/f[i]%f[j]==0)
			{
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
} 
