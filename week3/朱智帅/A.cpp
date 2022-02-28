#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
int main()
{
	unsigned long long sum = 0;
	int i;
	for (i = 0; i <= 2019; i++)
	{
		int k = i;
		while (k)
		{
			int K = k % 10;
			if (K == 2 || K == 0 || K == 1 || K == 9)
			{
				sum = sum + i * i;
				break;
			}
			k = k / 10;
		}
	}
	cout << sum << endl;
	return 0;
}