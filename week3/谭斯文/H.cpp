#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    int a[n+1],b[n+1];
    for(i=1;i<=n;i++)
    {
    	cin>>a[i];
    	b[i]=a[i];
	}
    for(i=2;i<=n;i++)
    {
    	sort(b+1,b+i);
    	for(j=1;j<i;j++)
    	{
    		if(b[j]==a[i])
    		{
    			a[i]++;
    			b[i]++;
			}	
		}
	}
    for(i=1;i<=n;i++)
    {
    	cout<<a[i];
    	if(i!=n)
    	cout<<" ";
	}	
	return 0;
}
