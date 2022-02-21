
#include<iostream>
using namespace std;
int counts = 1;
int main()
{
	for (int i = 2; i <= 20; i++)
	{
		counts += (i - 1) * 4;
	}
	cout << counts;
}

