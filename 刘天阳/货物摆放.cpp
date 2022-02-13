#include <bits/stdc++.h>
using namespace std;
map<long long, long long>a;
int t = 0;
long long st = 2021041820210418;
int main()
{
	for (int i = 1; i <= sqrt(st); i++)
	{
		if(st%i == 0) {
			a[++t] = i;
			a[++t] = st / i;
		}
	}
	int ans = 0;
	for (int i = 1; i <= t; i++)
		for (int j = 1; j <= t; j++)
			for (int k = 1; k <= t; k++)
			{
				if(a[i]*a[j]*a[k] == st) ans ++;
			}
	cout << ans;
	return 0;
}
