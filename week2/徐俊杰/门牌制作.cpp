#include <iostream>
using namespace std;
int main()
{
	int cnt2 = 0;
	for (int i = 1; i <= 2020; i++)
	{
		int t = i;
		while (t > 0)
		{
			if (t % 10 == 2) cnt2++;
			t /= 10;
		}
	}
	cout << cnt2 << endl;
	return 0;
}