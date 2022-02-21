//答案：2658417853

#include<iostream>
#include<string>
using namespace std;
int main()
{
	long long sum = 0;
	for (int i = 1; i <= 2019; i++)
	{
		if (to_string(i).find('2') != -1 || to_string(i).find('0') != -1 || to_string(i).find('1') != -1 || to_string(i).find('9') != -1)
			sum = sum + i * i;
	}
	cout<<sum;
	return 0;
}