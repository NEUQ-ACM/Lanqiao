#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	int min = 101, max = 0;
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		if (min >= p[i]) min = p[i];
		if (max <= p[i]) max = p[i];
		sum += p[i];
	}
	cout << max << endl;
	cout << min << endl;
	cout << fixed << setprecision(2) << sum / n << endl;
	return 0;
}