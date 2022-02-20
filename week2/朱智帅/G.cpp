#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int norun[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }, run[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int main()
{
	int A = 0, B = 0;
	long long n, i;
	cin >> n;
	for (i = n + 1; i < 99999999; i++)
	{
		int year = i / 10000, month = (i / 100) % 100, day = i % 100;
		if (month == 0 || month > 12) continue;
		if (day == 0) continue;
		if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && day > run[month])
		{
			continue;
		}
		else if (day > norun[month]) continue;
		else if (A == 0 || B == 0)
		{
			int ymonth = (year % 10) * 10 + (year % 100) / 10;
			int yday = ((year / 100) % 10) * 10 + year / 1000;
			if (ymonth == month && yday == day)
			{
				if (!A)cout << i << endl;
				A = 1;
				if (month == day)
				{
					cout << i << endl;
					B = 1;
				}
			}
		}
		if (A && B) break;
	}
}