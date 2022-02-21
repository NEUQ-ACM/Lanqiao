#include <bits/stdc++.h>
using namespace std;
int tot[10];
int now = 0;
bool calc(int x)
{
	while (x)
	{
		int t = x % 10;
		x /= 10;
		if (!tot[t]) return false;
		tot[t]--;
	}
	return true;
}
int main()
{
	for (int i = 0;i <= 9; i++)
	{
		tot[i] = 2021;
	}
	while (calc(++now));
	now--;
	printf("%d\n",now);
	return 0;
}
