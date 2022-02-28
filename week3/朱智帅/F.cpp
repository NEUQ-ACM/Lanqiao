#include<iostream>
#include<cmath>
using namespace std;
long long n = 1001733993063167141;
long long d = 212353;
long long c = 20190324;
long long p = 891234941;
long long q = 1123984201;
long long phi = (p - 1) * (q - 1);
int main()
{
	int N, i, sum[100001] = { 0 }, num, H;
	cin >> N;
	for (i = 1;; i++)
	{
		if (pow(2, i) - 1 >= N)
		{
			H = i;
			break;
		}
	}
	for (i = 1; i <= pow(2,H)-1; i++)
	{
		if (i <= N) cin >> num;
		else num = 0;
		sum[i] = sum[i - 1] + num;
	}
	int high[100001];
	
	int max = 1;
	for (i = 1; i <= H; i++)
	{
		high[i] = sum[(int)(pow(2, i)) - 1] - sum[int(pow(2, i - 1) - 1)];
		if (high[i] > high[max]) max = i;
	}
	cout << max << endl;
	return 0;
}