#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	const int n=12;
	for(int people=1;people>=1;people++)
	{
		int cnt=0;
		for(int i=1;i*i*2<=people;i++)
		{
			int j=people-i*i;
			int temp=sqrt(j);
			if(temp*temp==j)
			{
				cnt++;
			}
		}
		if(cnt==n)
		{
			cout<<people;
			break;
		}
	}
	return 0;
}
