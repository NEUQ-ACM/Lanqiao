#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long sum=0,jud;
	for(int i=1;i<=2019;i++)
	{
		jud=0;
		for(int j=i;j>0;j/=10)
		{
			int k=j%10;
			if(k==2||k==0||k==1||k==9)
			{
				jud=1;
				break;
			}	
		}
		if(jud)
		sum+=i*i;
	} 
	cout<<sum<<endl;
	return 0;
}
