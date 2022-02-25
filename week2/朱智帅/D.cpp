#include<iostream>
using namespace std;
int main()
{
	int n = (1 << 7), i, cnt = 0;
	for (i = 1; i < n; i++)
	{
		if (i & 1)
			if (!(i & (1 << 1) || i & (1 << 5))) continue;
		if (i & (1 << 1))
			if (!(i & (1<<0) || i & (1 << 2) || i & (1 << 6))) continue;
		if (i & (1 << 2))
			if (!(i & (1 << 1) || i & (1 << 3) || i & (1 << 6))) continue;
		if (i & (1 << 3))
			if (!(i & (1 << 2) || i & (1 << 4))) continue;
		if (i & (1 << 4))
			if (!(i & (1 << 3) || i & (1 << 5) || i & (1 << 6))) continue;
		if (i & (1 << 5))
			if (!(i & (1<<0) || i & (1 << 4) || i & (1 << 6))) continue;
		if (i & (1 << 6))
			if (!(i & (1 << 1) || i & (1 << 2) || i & (1 << 4) || i & (1 << 5))) continue;
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}