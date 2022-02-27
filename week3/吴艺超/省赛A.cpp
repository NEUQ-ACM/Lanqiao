#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
bool qs(int x)
{
	while(x)
	{
		int s=x%10;
		x/=10;
		if(s==2 || s==0 || s==1 || s==9)
		return 1;
	}
	return 0;
}
int main()
{
	for(int i=1;i<=2019;i++)
	{
		if(qs(i))
		ans=ans+i*i;
	}
	cout<<ans;
}

