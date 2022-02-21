#include <iostream>
using namespace std;
int main()
{
	int t = 1;
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
	bool p = false;
	while (t)
	{
		int temp = t;
		while (temp > 0)
		{
			int m = temp % 10;
			a[m]++;
			temp /= 10;
		}
		for (int i = 0; i < 10; i++)
		{
			if (a[i] > 2021)
			{
				p = true;
			}
		}
		if (p) break;
		t++;
	}
	t--;
	cout << t;
	return 0;
}