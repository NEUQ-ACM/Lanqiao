#include<bits/stdc++.h>
using namespace std;
bool runjudge(int x)
{
	if(x%100==0)
	{
		if(x%400==0)
		return 1;
		else
		return 0;
	}
	else
	{
		if(x%4==0)
		return 1;
		else
		return 0;
	}
}
int main()
{
	int ans=0;
	for(int i=1900;i<=9999;i++)
	{
		bool tjudge=0;
		int k=i;
		while(k)
		{
			if(k%10==2)
			tjudge=1;
			k/=10;
		}
		if(tjudge)
		{
			if(runjudge(i))
			ans+=366;
			else
			ans+=365;
		}
		else
		{
			if(runjudge(i))
			ans+=180;
			else
			ans+=179;
		}
	}
	cout<<ans;
}
