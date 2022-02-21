#include<iostream>
using namespace std;
int count(int num)
{
	int m=0,n=num;
	while(n)
	{
		if (n%10==1)
		m++;
		n/=10;
	}
	return m;
}
int main()
{
	int sum=0,i=1;
	while (sum<=2021)
	{
		sum+=count(i);
		i++;
	}
	cout<<i-1;
}