#include<bits/stdc++.h>
using namespace std;
bool isp(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0){return 0;}
	}
	return 1;
}
int main()
{
	int ans=0;
	for(int i=2;i<=2020;i++)
	{
		if(isp(i)){}
		else{ans++;}
	}
	printf("%d",ans);
} 
