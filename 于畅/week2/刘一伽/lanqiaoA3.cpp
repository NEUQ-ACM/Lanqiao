#include<iostream>
#include <vector>
#include<cmath>
using namespace std;
const long long n=2021041820210418;
int main()
{
	vector<long long> factor;
	for (int i = 1; i < sqrt(n); ++i)
	{
		if (n%i == 0)
		{
			factor.push_back(i);
			factor.push_back(n / i);
		}
	}
	int  ans = 0;
	int len = factor.size(); 
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
		{
			if(n%(factor[i]*factor[j])==0)
				ans += 1;
		}
	cout << ans << endl;
	return 0;
}
