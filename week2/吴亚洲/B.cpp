#include<bits/stdc++.h>
using namespace std;
int ans;
int gcd(int x,int y)
{
	int m=max(x,y);
	int n=min(x,y);
	if(m%n==0)
	return n;
	else
	return gcd(m%n,n);
}
int main()
{
	for(int i=1;i<=2020;i++)
	for(int j=1;j<=2020;j++)
	if(gcd(i,j)==1)
	ans++;
	cout<<ans;
} 
