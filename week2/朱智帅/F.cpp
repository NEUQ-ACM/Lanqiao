#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n, sum = 0, max = 0, min = 101;
	cin >> n;
	int N;
	N = n;
	while (N--)
	{
		int grade;
		cin >> grade;
		if (grade > max) max = grade;
		if (grade < min) min = grade;
		sum += grade;
	}
	cout << setiosflags(ios::fixed) << setprecision(2);
	cout << max << endl << min << endl << sum * 1.0 / n << endl;
	return 0;
}