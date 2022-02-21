#include<iostream>
using namespace std;
int main()
{
	int number[10], i, j, k;
	for (i = 0; i < 10; i++) number[i] = 2021;
	for (i = 1;; i++)
	{
		j = i;
		while (j)
		{
			number[j % 10]--;
			if (number[j % 10] == 0)
			{
				cout << i << endl;
				return 0;
			}
			j = j / 10;
			
		}
	}
	
	return 0;
}
