#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
int t;
int n, ans;
int num[23];
void dd(ll x)
{
	int cnt = 1;
	while (x)
	{
		if (x & 1)
			num[cnt]++;
		cnt++;
		x >>= 1;
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		memset(num, 0, sizeof(num));
		ans = 0;
		cin >> n;
		ll x;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			dd(x);
			ans ^= x;
		}
		if (ans == 0)cout << "0" << endl;
		else {
			for (int i = 20; i > 0; i--)
			{
				if (num[i] == 1)
				{
					cout << "1" << endl;
					break;
				}
				if (num[i] % 2 == 1)
				{
					if (n % 2 == 1)
					{

						cout << "1" << endl; 
						break;
					}
					else
					{
						cout << "-1" << endl; 
						break;
					}
				}
			}
		}
	}
}