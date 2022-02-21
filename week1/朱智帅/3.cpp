#include<iostream>
#include<cmath>
using namespace std;
unsigned long long i, j, k, sum = 0, zhiyinshu[10001], N = 2021041820210418, cnt = 0, Count[100001] = { 0 };
int main()
{
	
	for (i = 2; i <= N; i++)
	{
	    if(N % i == 0)
		{
			zhiyinshu[cnt++] = i;
			while (N % i == 0)
			{
				N = N / i;
				Count[cnt - 1]++;
			}
			cout << zhiyinshu[cnt - 1] << " "<<Count[cnt - 1] << endl;
		}
	}
	return 0;
}