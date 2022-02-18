#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
bool pan(int x)
{
	if((x%400==0)||((x%4==0) && (x%100!=0)))
		return 1;
	else return 0;
}
bool qs(int x)
{
	int s=0;
	while(x)
	{
		s=x%10;
		x/=10;
		if(s==2)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	for(int i=1900;i<=9999;i++)
	{
		if(qs(i))
		{
			if(pan(i))
			ans+=366;
			else ans+=365;
		}
		else{
			if(pan(i))
			ans=ans+151+29;
			else ans=ans+151+28;
		}
	}
	cout<<ans;
}
