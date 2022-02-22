#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int main()
{
	n = m = 20;
	ans = m * m +  (n + 1) * n / 2 + 2 * m * n - m + 1;
	cout<<ans;
	return 0;
} 