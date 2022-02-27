#include <bits/stdc++.h>
using namespace std;
int main()
{   
// 蓝桥杯的系统int就能通过，但是acwing要用long long 
	long long t = 1;
	long long ans = 1, n, maxx;
	cin >> n >> maxx;
	for (long long i = 1; t < n; i++)
	{
		long long a, k = 0;
		for (long long j = 1; j <= 1<<i && t < n; j++,t++)
		{
			cin >> a;
			k += a;
		}
//		prlong longf("i = %d k = %d\n",i, k);
		if(k > maxx)
		{
			maxx = k; ans = i+1;
		}
	}
	cout << ans;
	return 0;
}
