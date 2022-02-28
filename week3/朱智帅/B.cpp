#include<iostream>
using namespace std;
int main()
{
	int a1, a2, a3, a4;
	a1 = a2 = a3 = 1;
	for (int i = 4; i <= 20190324; i++)
	{
		a4 = a1 + a2 + a3;
		a4 %= 10000;
		a1 = a2;
		a2 = a3;
		a3 = a4;
	}
	cout << a4;
	return 0;
}