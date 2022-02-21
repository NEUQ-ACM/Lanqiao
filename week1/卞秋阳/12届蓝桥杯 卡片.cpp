#include<bits/stdc++.h>
using namespace std;
int a[10];
int n,b,c,m;
int pan(int n); 
int main()
{
	for(int i=0;i<=9;i++)
	{
		a[i]=2021;
	}
	b=0;
	while(pan(b+1))
	{
		b++;
	}
	cout<<b;
	return 0;	
	
}
int pan(int n)
{
	while(n)
	{
	
		m=n%10;
		a[m]--;
		if(a[m]==0) return 0;
		n=n/10;
		
	}
	return 1;
	
}
