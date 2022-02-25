#include<iostream>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	int a[200], num = 0;
	while (n > 1)
	{
		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				a[num] = i;
				num++;
				n = n / i;
				break;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}