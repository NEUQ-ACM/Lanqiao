#include<iostream>

using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	int cnt = 0;
	for (size_t i = 1; i <= 2020; i++)
	{
		for (size_t j = 1; j <= 2020; j++)
		{
			if (gcd(i, j) == 1)++cnt;
		}
	}
	cout << cnt;
}