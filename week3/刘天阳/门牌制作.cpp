#include <bits/stdc++.h>
using namespace std;
int main()
{
	int ans = 0;
	for (int i = 1; i <= 2020; i++)
	{
		int k = i;
		while(k)
		{
			int t = k % 10;
			k /= 10;
			if(t == 2) ans++;
		}
	}
	cout << ans;
	
	return 0;
}
