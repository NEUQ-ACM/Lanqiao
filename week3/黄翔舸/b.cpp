#include<iostream>
#include<string>
using namespace std;
#define ll long long 
int main()
{
ll qs = 1, fl = 1, cou = 1;
	for (ll i = 20190321; i > 0; i--)
	{
		ll bj = qs;
		qs = bj + fl + cou;
		fl = cou;
		cou = bj;
		qs = qs % 100000;
		fl = fl % 100000;
		cou = cou % 100000;
	}
	cout << qs;
	return 0;
}