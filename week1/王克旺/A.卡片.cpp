#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10]={0};
	for(int i=1;;i++)
	{
		int j=i,k;		
		while(j)
		{
			k=j%10;
			a[k]++;
			if(a[k]>2021)
			{
				if(j==0)
				{
					cout<<i;
					return 0;
				}				
				else
				{
					cout<<i-1;
					return 0;
				}
			}
			j/=10;
		}
	}	
}
