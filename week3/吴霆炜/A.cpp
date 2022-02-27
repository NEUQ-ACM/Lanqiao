#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll res=0;
	for(int i=1;i<=2019;i++)
	{
		int x=i;
		while(x)
		{
			if(x%10==2||x%10==0||x%10==1||x%10==9)
			{
				res+=i*i;
				break;
			}
			else
			{
				x=x/10;
			}
		}
	}
	cout<<res;
	return 0;
}