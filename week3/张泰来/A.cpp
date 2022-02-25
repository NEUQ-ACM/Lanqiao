#include <bits/stdc++.h>
using namespace std;
long long ans;
bool check(int x)
{
	while (x)
	{
		int t = x % 10;
		x /= 10;
		if (t == 2 || t == 0 || t == 1 || t == 9) return true;
	}
	return false;
}
int main()
{
	for (int i = 1;i <= 2019; i++)
	{
		if (check(i)) ans += i * i;
	}
	printf("%lld\n",ans);
	return 0;
}
