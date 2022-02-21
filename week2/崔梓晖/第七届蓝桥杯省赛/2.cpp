#include <bits/stdc++.h>
using namespace std;
int main()
{
	int sum[100],del[100];
	for(int i=1;i<=99;i++)
	{
		sum[i]=sum[i-1]+i;
	}
	for(int i=1;i<=98;i++)
	{
		for(int j=2;j<=99;j++)
		{
			if(sum[j]-sum[i]==236)
			{
				cout<<i+1<<endl;
			}
		}
	}
	return 0;
}
