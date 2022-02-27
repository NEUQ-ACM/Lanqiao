#include<iostream>
using namespace std;
int a[100005];
bool vis[1000005];
int vis2[1000005] = { 0 };
int main()
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (vis[num]==0)
		{
			a[i] = num;
			vis[num] = 1;
		}
		else
		{
			int k = num;
			if (vis2[num]) num = vis2[num];
			while (vis[num]==1)
			{
				num++;
			}
			vis2[k] = num + 1;
			a[i] = num;
			vis[num] = 1;
		}
	}
	for (int i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}