#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int m;
	m = log(n + 1) / log(2);
	long long max = -1000;
	for (int i = 1; i <= m; i++)
	{
		long long sum = 0;
		for (int j = pow(2, i - 1) - 1; j < pow(2, i) - 1; j++)
		{
			sum += p[j];
		}
		if (sum > max) max = sum;
	}
	cout << max << endl;
	return 0;
}