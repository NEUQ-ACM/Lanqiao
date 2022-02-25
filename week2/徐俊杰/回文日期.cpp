#include <iostream>
using namespace std;
bool run(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) return true;
	else return false;
}
bool judge1(int x)
{
	int year = x / 10000;
	int month = (x % 10000) / 100;
	int date = year % 100;
	if (month > 12 || date > 31 || month == 0) return false;
	if (run(year))
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (date <= 30) return true;
		}
		else if (month == 2 && date <= 29) return true;
		else
		{
			if (date <= 31) return true;
		}
		return false;
	}
	else if (!run(year))
	{
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			if (date <= 30) return true;
		}
		else if (month == 2 && date <= 28) return true;
		else
		{
			if (date <= 31) return true;
		}
		return false;
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	int a[5],b[5];
	a[1] = n / 10000000;
	a[2] = (n % 10000000) / 1000000;
	a[3] = (n % 1000000) / 100000;
	a[4] = (n % 100000) / 10000;
	b[1] = a[1];
	b[2] = a[2];
	b[3] = a[3];
	b[4] = a[4];
	while (1)
	{
		int Nnum = a[1] * 10000001 + a[2] * 1000010 + a[3] * 100100 + a[4] * 11000;
		if (Nnum > n)
		{
			if (judge1(Nnum))
			{
				cout << Nnum << endl;
				break;
			}
			else
			{
				a[4]++;
				if (a[4] >= 10)
				{
					a[4] = a[4] % 10;
					a[3]++;
				}
				if (a[3] >= 10)
				{
					a[3] = a[3] % 10;
					a[2]++;
				}if (a[2] >= 10)
				{
					a[2] = a[2] % 10;
					a[1]++;
				}
			}
		}
		else
		{
			a[4]++;
			if (a[4] >= 10)
			{
				a[4] = a[4] % 10;
				a[3]++;
			}
			if (a[3] >= 10)
			{
				a[3] = a[3] % 10;
				a[2]++;
			}if (a[2] >= 10)
			{
				a[2] = a[2] % 10;
				a[1]++;
			}
		}
	}
	while (1)
	{
		int Nnum = b[1] * 10000001 + b[2] * 1000010 + b[3] * 100100 + b[4] * 11000;
		if (Nnum > n && b[1] == b[3] && b[2] == b[4])
		{
			if (judge1(Nnum))
			{
				cout << Nnum << endl;
				break;
			}
			else
			{
				b[4]++;
				if (b[4] >= 10)
				{
					b[4] = b[4] % 10;
					b[3]++;
				}
				if (b[3] >= 10)
				{
					b[3] = b[3] % 10;
					b[2]++;
				}if (b[2] >= 10)
				{
					b[2] = b[2] % 10;
					b[1]++;
				}
			}
		}
		else
		{
			b[4]++;
			if (b[4] >= 10)
			{
				b[4] = b[4] % 10;
				b[3]++;
			}	
			if (b[3] >= 10)
			{	
				b[3] = b[3] % 10;
				b[2]++;
			}if (b[2] >= 10)
			{
				b[2] = b[2] % 10;
				b[1]++;
			}
		}
	}
	return 0;
}