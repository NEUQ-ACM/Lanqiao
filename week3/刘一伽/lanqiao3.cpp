#include<iostream>

using namespace std;

int main()
{
	int n = 20;
	n = n*2-1;
	int ans = 0,sum =  0;
	for(int i = 1; i <=n ;i++)
	{
		sum+=i; 
	} 
	ans = (sum+sum-n+1)/2;
	cout << ans <<endl;
	return 0;
	 
} 

