#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,ans=0;
	for(int i=27;i<=99;i++)
	{
		a=i%10;
		b=i/10;
		if(i-27==a*10+b)
		{
		//	cout<<i<<endl;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
