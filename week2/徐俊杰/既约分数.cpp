#include <iostream>
using namespace std;
bool judge(int x, int y)
{
	int t = y % x;
	while (t > 0)
	{
		y = x;
		x = t;
		t = y % x;
	}
	if (x > 1) return false;
	else if (x == 1) return true;
}
int main()
{
	int cnt = 0;
	for (int i = 1; i <= 2020;i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (judge(j, i))
			{
				cnt++;
			}
		}
	}
	cnt *= 2;
	cout << cnt;
	return 0;
}
