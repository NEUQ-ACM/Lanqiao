#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
bool pan(int x)
{
	for(int i=2;i<=sqrt(x)+1;i++)
	{
		if(x%i==0)
		return 1;
	}
	return 0;
}
int main()
{
	for(int i=4;i<=2020;i++)
	{
		if(pan(i))ans++;
	}
	cout<<ans;
}
