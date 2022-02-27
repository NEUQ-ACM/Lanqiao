#include<iostream>
using namespace std;
int main()
{
	int n;
	float min = 9999999, max = -1, sum = 0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		int lsz;
		scanf("%d", &lsz);
		if (lsz < min)min = lsz;
		if (lsz > max)max = lsz;
		sum += lsz;
	}
	float en = sum / n;
	cout << max << '\n' << min << '\n';
	printf("%.2f", en + 0.005);
}