#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,a,ans=0;
	cin>>n;
	a=n;
	while(a>=3)
	{
		ans=ans+a/3;
		a=a%3+a/3;
	}
	cout<<ans+n;
	return 0;
}
