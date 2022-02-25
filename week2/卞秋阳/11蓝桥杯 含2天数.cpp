#include<bits/stdc++.h>
#define ll long long
using namespace std;
int ans;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	for(int i=1;i<=2020;i++)
		for(int j=1;j<=2020;j++)
		{
			if(gcd(i,j)==1)ans++;
		}
	cout<<ans;
}
