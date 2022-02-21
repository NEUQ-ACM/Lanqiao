#include<iostream>

using namespace std;

int main()
{
	int t;
	size_t sum = 0;
	bool flag = 0;
	for (size_t i = 1; i < 2020; i++)
	{
		t = i;
		flag = 0;
		do
		{
			if (t % 10 == 2 || t % 10 == 0 || t % 10 == 1 || t % 10 == 9)flag = 1;
			t /= 10;
		} while (t > 0);
		if (flag)sum += (i * i);
	}
	cout << sum;
}