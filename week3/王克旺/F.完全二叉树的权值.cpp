#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main()
{
	int n; 
	cin>>n;
	int depth=1,num=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int max=a[1],ans=1;
	for(;;)
	{
		int sum=0;
		depth++;
		num*=2;
		for(int i=pow(2,depth-1);i<=num&&i<=n;i++)
		{
		    sum+=a[i];	
		}
		if(sum>max)
		{
			max=sum;
			ans=depth;
		}
		if(num>n)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
