#include <iostream>
using namespace std;
int main()
{
	int maxx = -1, minn = 101, n;
	float p, sum;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int a; cin >> a;
		maxx = max(a, maxx);
		minn = min(a, minn);
		sum += a;
	}
	cout << maxx << endl << minn << endl;
	printf("%.2f",sum/n);
	return 0;
}
