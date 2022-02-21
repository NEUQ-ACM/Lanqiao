#include <bits/stdc++.h>
using namespace std;
bool che(long long a)
{
	while(a)
	{
		
		long long k = a%10;
		a /= 10;
		if(k == 2 || k == 0 || k == 1 || k == 9) return 1;	
		
	}
	return 0;
}
int main()
{
	long long ans = 0;
	for (long long i = 1; i <= 2019; i++)
	{
		if(che(i)) 
		{
//			cout << i << endl; 
			ans += i*i;
		}
	}
	cout << ans;
	return 0;
}
