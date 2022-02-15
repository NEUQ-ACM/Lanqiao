#include<iostream>
#include<string>
using namespace std;
unsigned long long ans;
int main()
{
	for (int i = 1; i <= 2019; i++)
	{
		string s = to_string(i);
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == '2' || s[j] == '0' || s[j] == '1' || s[j] == '9')
			{
				ans += i * i;
				break;
			}
		}
	}
	cout << ans;
	return 0;
}

