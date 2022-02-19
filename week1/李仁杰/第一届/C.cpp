#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

string s1, s2;

void f()
{
	for (int i = 0; i < s2.length(); i++)
	{
		if (s2[i] == 'A') s2[i] = 'T';
		else if (s2[i] == 'T') s2[i] = 'A';
		else if (s2[i] == 'G') s2[i] = 'C';
		else s2[i] = 'G';
	}
}

int main()
{
	while (cin >> s1 >> s2)
	{
		f();
		if (s1.find(s2))
		{
			cout << s1.find(s2) + 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}