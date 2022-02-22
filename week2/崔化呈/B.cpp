#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	return x%y>0?gcd(y,x%y):y;
}
int main()
{
	int ans=0;
	for(int i=1;i<=2020;i++)
	{
		for(int j=1;j<=2020;j++)
		{
			int g=gcd(i,j);
			if(g==1){ans++;}
		}
	}
	cout<<ans;
}
