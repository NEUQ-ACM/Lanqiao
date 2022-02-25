
#include<iostream>
using namespace std;
int counts;

int main()
{
	for (int i = 1; i <= 2020; i++)
		for (int j = 1; j <= 2020; j++)
		{
			if (chang(i, j) == 1)counts++;
		}
	cout << counts;
}
int chang(int x, int y)
{
	return y == 0 ? x : chang(y, x % y);
}