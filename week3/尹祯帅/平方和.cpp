#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long ans=0;
	for(int i=1;i<=2019;i++)
	{
		int t=i;
		bool jud=0;
		while(t)
		{
			int tt=t%10;
			if(tt==2||tt==0||tt==1||tt==9)
			{
				jud=1;
				break;
			}
			t/=10;
		}
		if(jud) ans+=i*i;
	}
	cout<<ans;
	return 0;
} 

//2658417853
