#include <bits/stdc++.h>
using namespace std;
int ans;
int main()
{
	for (int i = 1;i <= 38; i++)
	{
		ans += i;
	}
	ans += 20;
	printf("%d\n",ans);
	return 0;
}
