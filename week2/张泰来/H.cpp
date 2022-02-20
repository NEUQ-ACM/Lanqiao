#include <bits/stdc++.h>
using namespace std;
char s[100005];
int nexts[27][100005];
long long ans;
int main()
{
	scanf("%s",s + 1);
	s[0] = 'a';
	int len = strlen(s);
	len--;
	for (int i = 1;i <= 26; i++)
	{
		nexts[i][len] = len + 1;
		for (int j = len - 1;j >= 1; j--)
		{
			if (s[j + 1] == 'a' + i - 1) nexts[i][j] = j + 1;
			else nexts[i][j] = nexts[i][j + 1];
		}
	}
	for (int i = 1;i <= 26; i++)
	{
		int last = ans;
		for (int j = 1;j <= len; j++)
		{
			if (s[j] == 'a' + i - 1) 
				ans += nexts[i][j] - j;
			 else {
			 	int t = nexts[i][j];
				if (nexts[i][t]) ans += nexts[i][t] - t;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
