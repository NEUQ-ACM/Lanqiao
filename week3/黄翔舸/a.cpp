#include<iostream>
#include<string>
using namespace std;
#define ll long long
int main()
{
	ll sum = 0;
	for (int j = 1; j <= 2019; j++)
	{
		if (to_string(j).find('2') != -1 || to_string(j).find('0') != -1 || to_string(j).find('1') != -1 || to_string(j).find('9') != -1)
			sum+=j*j;
	}
	cout << sum;
	return 0;
}