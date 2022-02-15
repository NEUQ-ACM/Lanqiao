#include <bits/stdc++.h>
using namespace std;
int n,T,cnt1,cnt2,k;
int a[200005];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		cnt1 = cnt2 = k = 0;
		scanf("%d",&n);
		for (int i = 1;i <= n; i++)
		{
			scanf("%d",a + i);
			k ^= a[i];
		}
		if (k == 0) 
		{
			printf("0\n");
			continue;
		}
		k = log2(k);
		for (int i = 1;i <= n; i++)
		{
			if (a[i] & (1 << k)) cnt2++;
			else cnt1++;
		}
		if (cnt2 == 1 || ((cnt1 + cnt2) & 1)) printf("1\n");
		else printf("-1\n");
	}
	return 0;
} 
 
