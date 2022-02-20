#include<iostream>

using namespace std;

int main()
{
	int a = 1, b = 1, c = 1, d;
	for (size_t i = 4; i <= 20190324; i++)
	{
		d = a + b + c;
		d %= 10000;
		a = b; b = c; c = d;
	}
	cout << d;
}