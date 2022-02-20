#include<bits/stdc++.h>
using namespace std;
int main()
{
	int cnt=0;
	for(int i=1;i<=2020;i++)
	{
		int j=i;
		while(j)
		{
			int k=j%10;
			if(k==2)
			{
				cnt++;
			}
			j=j/10;
		}
	}
	cout<<cnt;
	return 0;
}
