#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(a%b==0)
	{
		return b;
	}
	gcd(b,a%b);
}
int main()
{
	int cnt=0;
	for(int i=1;i<=2020;i++)
	{
		for(int j=1;j<=2020;j++)
		{
			if(gcd(i,j)==1)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
