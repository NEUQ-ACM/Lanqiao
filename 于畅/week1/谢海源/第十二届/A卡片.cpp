#include<bits/stdc++.h>
using namespace std;
const int maxn=2021;
int a[10];
bool check(int n)
{
	int x;
	while(n)
	{
		x=n%10;
		if(a[x])
		{
			a[x]--;
		}
		else return 0;
		n=n/10;
	}
	return 1;
}
int main()
{
	for(int i=0;i<=9;i++)
	{
		a[i]=maxn;
	}
	int n=1;
	while(check(n))
	{
		n++;	
	}
	cout<<n-1;
    return 0;
}
