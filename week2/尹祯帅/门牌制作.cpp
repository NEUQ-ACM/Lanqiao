#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	for(int i=1;i<=2020;i++)
	{
		for(int t=i;t;t/=10)
		{
			if(t%10==2) ans++;
		}
	}
	cout<<ans;
	return 0;
} 

//624
