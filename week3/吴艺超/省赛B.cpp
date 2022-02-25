#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[20190325];
int main()
{
	a[1]=1,a[2]=1,a[3]=1;
	for(int i=4;i<=20190324;i++)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3];
		if(a[i]>=1000)
		a[i]%=10000;
	}
	cout<<a[20190324];
}
