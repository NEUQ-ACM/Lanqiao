#include<iostream>
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, number, count[21] = {0};
		cin >> n;
		//cout << "T:" << T << endl;
		int i, sum = 0;
		for (i = 0; i < n; i++)
		{
			cin >> number;
			//cout <<endl<<"number:"<< number << endl;
			int k = number;
			sum = sum ^ number;
			int j;
			for (j = 0;; j++)
			{
				if ((1 << j) & k) count[j]++;
				if ((1 << j) > k) break;
			}
		}
		if (sum == 0)
		{
			cout << "0" << endl;
		}
		else
		{
			for (i = 20; i >= 0; i--)
			{
				if (count[i] == 1)
				{
					cout << "1" << endl;
					break;
				}
				else if (count[i] % 2 == 1)
				{
					if (n % 2 == 1) cout << "1" << endl;
					else cout << "-1" << endl;
					break;
				}
			}
		}
	}
	return 0;
}