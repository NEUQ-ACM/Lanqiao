#include<bits/stdc++.h>
using namespace std;
#define int long long
bool pd(int x)
{
	while(x)
	{
		int a=x%10;
		if(a==2||a==0||a==1||a==9)
		{
			return 1;
		}
		x=x/10;
	}
	return 0;
}
signed main()
{
	int sum=0;
	for(int i=1;i<=2019;i++)
	{
		if(pd(i)) sum+=i*i;
	}
	cout<<sum;
    return 0;
}
