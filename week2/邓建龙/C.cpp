#include<iostream>
using namespace std;
int a[1000][1000], num = 1, i = 1, j = 1;
int main()
{
	a[1][1] = 1;
	while (num < 10000) {
		i == 1 ? j++, a[i][j] = ++num : a[i][j] = ++num;
		while (j > 1) a[++i][--j] = ++num;
		j == 1 ? i++, a[i][j] = ++num : a[i][j] = ++num;
		while (i > 1) a[--i][++j] = ++num;
	}
	int ans = a[20][20];
	cout << ans << endl;
	return 0;
}