#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x=1,y=1,z=1,ans;
	for(int i=4;i<=20190324;i++)
	{
		ans=(x+y+z)%10000;
		x=y;
		y=z;
		z=ans;
	}
	cout<<ans;
	return 0;
}
