#include<bits/stdc++.h>
using namespace std;
vector<long long> A;

int main(void)
{
	long long n=2021041820210418;
	
	for(long long i=1; i*i<n; i++)
		if(n%i==0)
		{
			A.push_back(i);
			A.push_back(n/i);
		}
	
	int res=0;
	for(auto i:A)
        for(auto j:A)
            for(auto k:A)
                if(i*j*k==n)
					res++;
	
	cout<<res;
	
	return 0;
}