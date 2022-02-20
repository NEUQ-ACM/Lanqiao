#include<iostream>
using namespace std;

int main()
{
	int cnt = 0;
	for (int i = 1; i <= 2020; i++)
	{
		int tmp = i;
		while (tmp)
		{
			if (tmp % 10 == 2)
				cnt++;
			tmp /= 10;
		}
	}
	cout << cnt;
	return 0;
}
