#include <bits/stdc++.h>
using namespace std;
int main()
{
	int i,j,n,s,w[1001],a[1001],max=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]=a[i]+a[i-1];
	}
	for(i=1,j=1;j<=n;i++,j=(j<<1)+1)
	{
		w[i]=a[j]-a[j>>1];
	}
	if((j>>1)<n) w[i]=a[n]-a[j>>1];
	else i--;
	for(j=1;j<=i;j++)
		if(w[j]>max)
		{
			max=w[j];
			s=j;
		}
	cout<<s;
	return 0;
 } 
