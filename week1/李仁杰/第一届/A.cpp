#include<iostream>
using namespace std;

int main()
{
	int n, m, ans;
	cin >> n >> m;
	if (n % 3 == 2)
	{
		ans = (n / 3 * 2 + 1) * (m - m / 5);
	}
	else
	{
		ans = n / 3 * 2 * (m - m / 5);
	}
	cout << ans;
	return 0;
}