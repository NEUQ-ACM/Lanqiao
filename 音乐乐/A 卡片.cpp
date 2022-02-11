#include<bits/stdc++.h>
using namespace std;
int a[10];

int main()
{
	for(int i=0;i<10;i++) a[i]=2021;
	int t=1,flag=1;
	while(1)
	{
		int temp=t;
		while(temp)
		{
			if(a[temp%10])
				a[temp%10]--,temp/=10;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag) t++;
		else break;
	}
	cout<<t;
} 
