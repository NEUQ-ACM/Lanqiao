#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int n, a[305];

void f(int i)
{
	if (i + 8 > n) return;
	int now = i + 8;
	a[now]++;
	f(now);
	while (now <= n)
	{
		now += 3;
		a[now]++;
		f(now);
	}
}

int main()
{
	int ans = 1;
	cin >> n;
	f(0);
	for (int i = 1; i <= n; i++)
	{
		ans += a[i];
	}
	cout << ans;
}