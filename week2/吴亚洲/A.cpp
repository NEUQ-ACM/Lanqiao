#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ans=0;
	for(int i=1;i<=2020;i++)
	{
		int x=i;
		while(x)
		{
			if(x%10==2)
			ans++;
			x/=10;
		}
	}
	cout<<ans;
 } 
