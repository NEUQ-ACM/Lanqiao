#include<bits/stdc++.h>
using namespace std;
int carn[11];

bool dis(int n)
{
	while(n)
	{
		if(--carn[n%10]<0)
			return 0;
		n/=10;
	}
	return 1;
}

int main(void)
{
	for(int i=0; i<10; i++)
		carn[i]=2021;
	
	int i=1;
	while(dis(i))
		i++;
	
	cout<<i-1;
	
	
	return 0;
}