#include <bits/stdc++.h>
using namespace std;
struct zuobiao{
	double x, y;
};
map<pair<double, double>, int> b;
zuobiao a[50000];
int main()
{
	long long t = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 21; j++)
		{
			a[++t].x = i, a[t].y = j;
		}
	
	long long ans = 0;
	for (int i = 1; i <= t; i++)
		for (int j = i + 1; j <= t; j++)
		{
			double x1 = a[i].x, x2 = a[j].x, y1 = a[i].y, y2 = a[j].y;
			if(x1 == x2) continue;
			double k = (y2-y1) / (x2-x1);
			double b2 = (x2*y1-y2*x1) / (x2-x1);
			
			if(!b[{k,b2}]) 
			{
				b[{k,b2}] = 1;
				ans++;
			}
		}
	cout << ans + 20;
	return 0;
}
