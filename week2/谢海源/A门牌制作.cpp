#include<bits/stdc++.h>
using namespace std;
int f(int a)
{
	int s=0;
	while(a)
	{
		if(a%10==2) s++;
		a=a/10;
	}
	return s;
}
int main()
{
	int sum=0;
	for(int i=1;i<=2020;i++)
	{
		sum+=f(i);
	}
	cout<<sum;
    return 0;
}
