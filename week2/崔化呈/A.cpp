#include<bits/stdc++.h>
using namespace std;
int num=0;
void cal(int n)
{
	while(n!=0)
	{
		if(n%10==2){num++;}
		n/=10;
	}
}
int main()
{
	for(int i=2;i<=2020;i++)
	{
		cal(i);
	}
	printf("%d",num);
}
