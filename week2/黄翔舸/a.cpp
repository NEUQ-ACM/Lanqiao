#include<iostream>
using namespace std;
#define ll long long
using namespace std;
int ans;

int main()
{
	for (int i = 1; i <= 2020; i++)
	{
		ll temp = i;
		while (temp)
		{
			if (temp% 10 == 2)
				ans++;
			temp /= 10;
		}
	}
	cout << ans;
}