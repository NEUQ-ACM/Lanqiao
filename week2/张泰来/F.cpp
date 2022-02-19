#include <bits/stdc++.h>
using namespace std;
int n,t;
int maxx = -1,minn = 1e9;
double average;
int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",&t);
		maxx = max(maxx,t);
		minn = min(minn,t);
		average += t; 
	}
	average = average * 1.0 / n;
	printf("%d\n%d\n",maxx,minn);
	printf("%.2f\n",average);
	return 0;
}
