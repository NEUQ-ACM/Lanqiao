#include <bits/stdc++.h>
using namespace std;
int ans;
void calc(int x)
{
	while (x)
	{
		int t = x % 10;
		x /= 10;
		if (t == 2) ans++;
	}
	return;
}
int main()
{
	for (int i = 1;i <= 2020; i++)
	{
		calc(i);
	}
	printf("%d",ans);
	return 0;
} 
