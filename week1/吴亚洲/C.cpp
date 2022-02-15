#include<bits/stdc++.h>
using namespace std;
vector<long long> base;
vector<int> Pow;
int main()
{
	long long x=2021041820210418;
	for(long long i=2;i<=x;i++)
	{
		if(x%i==0)
		{
			base.push_back(i);
			int cnt=0;
			while(x%i==0)
			{
				x/=i;
				cnt++;
			}
			Pow.push_back(cnt);
		}
	}
	for(int i=0;i<base.size();i++)
	cout<<base[i]<<"  "<<Pow[i]<<endl;
} 
