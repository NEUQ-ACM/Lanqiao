#include<bits/stdc++.h>
using namespace std;
int ans=0;
void cuntm(int a)
{
	do
	{
		if(a%10==2)
			ans++;
		a/=10;
	}
	while(a);
}
int main(void)
{
	for(int i=1; i<=2020; i++)
		cuntm(i);
	
	cout<<ans;
	
	return 0;
}