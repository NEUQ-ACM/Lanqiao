#include <bits/stdc++.h>
using namespace std;
map <int,int> tot;
vector <int> v;
long long n = 2021041820210418;
int ans = 1;
int main()
{
	for (int i = 2;i <= sqrt(n); i++)
	{
		if (n % i) continue;
		n /= i;
		tot[i]++;
		v.push_back(i);
		while (n % i == 0) 
		{
			tot[i]++;
			n /= i;
		}
	}
	if (n) 
	{
		v.push_back(n);
		tot[n]++;
	}
	for (int i = 0;i < v.size(); i++)
	{
		int m = tot[v[i]];
		ans *= (m + 1) * (m + 2) / 2;
	}
	printf("%d\n",ans);
	return 0;
} 
