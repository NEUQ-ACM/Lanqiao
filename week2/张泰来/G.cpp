#include <bits/stdc++.h>
using namespace std;
int n,cnt1,cnt2;
int dates[10005],dat[10005],days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
void check(int x)
{
	int a = x / 1000;
	int b = x / 100 % 10;
	int c = x % 100 / 10;
	int d = x % 10;
	int month = d * 10 + c;
	int day = b * 10 + a;
	if (month == 0 || month > 12) return;
	if (day > days[month]) return;
	int t = x * 10000 + d * 1000 + c * 100 + b * 10 + a;
	dates[++cnt1] = t;
	if (a == c && b == d) dat[++cnt2] = t;
	return;
}
int main()
{
	for (int i = 1000;i <= 9090; i++)
	{
		check(i);	
	}
	scanf("%d",&n);
	int pos1 = upper_bound(dates + 1,dates + cnt1 + 1,n) - dates;
	int pos2 = upper_bound(dat + 1,dat + cnt2 + 1,n) - dat;
	printf("%d\n",dates[pos1]);
	printf("%d\n",dat[pos2]);
} 
