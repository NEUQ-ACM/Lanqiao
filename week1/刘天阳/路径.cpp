#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
	int num1 = max(a, b), num2 = min(a, b);
	if(num1 % num2 == 0) return num2;
	else return gcd(num2, num1%num2);
}
int a[2023][2023];
int main()
{
	for (int i = 1; i <= 2021; i++)
		for (int j = 1; j <= 2021; j++)
		{
			int der = abs(i - j);
			if(i == j) a[i][j] = 0;
			else if(der > 21) a[i][j] = 111111111;
			else {
				a[i][j] = i * j / gcd(i, j);
			}
		}
	for (int k = 1; k <= 2021; k++)
		for (int j = 1; j <= 2021; j++)
			for (int i = 1; i <= 2021; i++)
			{
				a[i][j] = min(a[i][j], a[j][k] + a[k][i]);
			}
	cout << a[1][2021];
	return 0;
}
