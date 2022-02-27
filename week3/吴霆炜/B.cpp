#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll x=1,y=1,z=1,res;
	for(int i=4;i<=20190324;i++)
	{
		res=(x+y+z)%10000;
		x=y;
		y=z;
		z=res;
	}
	cout<<res;
	return 0;
}