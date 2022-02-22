#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,sum=0;
	for(i=1;i<=2020;i++)
	{
		j=i;
		for(;j>0;j/=10)
		{
			if(j%10==2)
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
