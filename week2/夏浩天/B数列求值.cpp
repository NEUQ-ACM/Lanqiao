//答案：4659

#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a=1, b=1, c = 1;
	for (int i = 20190321; i >0; i--)
	{
		int d = a;
		a = d + b + c;
		b = c;
		c = d;
		a = a % 10000;
		b = b % 10000;
		c = c % 10000;
	}
	cout<<a;
	return 0;
}