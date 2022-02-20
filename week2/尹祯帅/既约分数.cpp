#include<bits/stdc++.h>
using namespace std;
int main()
{
	int ans=0;
	ans=2020+2019;
	for(int i=2;i<=2020;i++)
	for(int j=2;j<=2020;j++)
	{
		bool jud=1;
		for(int k=2;k<=min(i,j);k++)
		{
			if(i%k==0&&j%k==0) 
			{
				jud=0;
				break;
			}
		}
		if(jud) ans++;
	}
	cout<<ans;
	return 0;
}

//2481215
