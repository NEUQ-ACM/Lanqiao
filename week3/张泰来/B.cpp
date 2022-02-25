#include <bits/stdc++.h>
using namespace std;
int f[20190325];
int main()
{
	f[1] = f[2] = f[3] = 1;
	for (int i = 4;i <= 20190324; i++)
	{
		f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % 10000;
	}
	printf("%d\n",f[20190324]);
	return 0;
}
