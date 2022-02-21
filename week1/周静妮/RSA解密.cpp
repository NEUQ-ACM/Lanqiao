//对n进行因式分解，得到其因子891234941和1123984201
#include<iostream>
using namespace std;
long long n= 1001733993063167141;
long long d = 212353;
long long c = 20190324;
int main()
{
	for (long long i = 2; i * i < n; i++)
	{
		if (n % i == 0) cout << i << " " << n / i;
	}
	return 0;
}

