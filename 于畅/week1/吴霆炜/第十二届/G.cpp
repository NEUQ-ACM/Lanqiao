#include <bits/stdc++.h>
using namespace std;
#define maxn 200005

int n,T,temp1,temp2,k;
int a[maxn];
int main()
{
	cin>>T;
	while (T--)
	{
		temp1 = temp2 = k = 0;
		cin>>n;
		for (int i = 1;i <= n; i++)
		{
			cin>>a[i];
			k ^= a[i];
		}
		if (k == 0) 
		{
			puts("0");
			continue;
		}
		k = log2(k);
		for (int i = 1;i <= n; i++)
		{
			if (a[i] & (1 << k)) temp2++;
			else temp1++;
		}
		if (temp2 == 1 || ((temp1 + temp2) & 1)) puts("1");
		else puts("-1");
	}
	return 0;
} 