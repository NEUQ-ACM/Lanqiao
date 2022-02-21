#include <bits/stdc++.h>
using namespace std;
map<int,int> a;   // 用map数据足够大，跑不到一分钟就出来了 
int main()
{
	a[1] = 1, a[2] = 1, a[3] = 1;
	for (int i = 4; i <= 20190324; i++)
	{
		a[i] = a[i-1] + a[i-2] + a[i-3];
		a[i] %= 10000;
	}
	cout << a[20190324];
	
	return 0;
}
