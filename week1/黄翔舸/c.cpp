#include<iostream>
#define l long long
using namespace std;
int ans;
l n = 2021041820210418;
int main()
{
	for (l i = 1; i * i * i <= n; i++)//???????????¨°¡Á?
	{
		if (n % i != 0)continue;
		l tmp = n / i;
		for (l j = 1; j * j <= tmp; j++)
		{
			if (tmp % j != 0)continue;
			l k = tmp / j;
			if (k<j || i>j)continue;
			if (i == j && i == k)ans++;
			else if (i == j || i == k || j == k)ans += 3;
			else ans += 6;
		}
	}
	cout << ans;
}