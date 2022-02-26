//90
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
int n;
int a[100005];
int v[1000005];
int main()
{
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	v[a[1]]=1;
	for(register int i=2;i<=n;i++)
	{
		if(!v[a[i]])v[a[i]]=1;
		else
		{
			while(1)
			{
				a[i]++;
				if(!v[a[i]])
				{
					v[a[i]]=1;
					break;
				}
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
