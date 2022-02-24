#include <bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			for(int k=1;k<=500;k++)
			{
				if((i*i+j*j+k*k)==1000)
				{
					cout<<i<<endl;
				}
			}
		}
	}
	return 0;
}

