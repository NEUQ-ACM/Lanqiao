#include<bits/stdc++.h>
using namespace std;
int main()
{
	int num[10],s=0;
	memset(num,0,sizeof(num));
	while(1)
	{
		if(num[1]==2021){printf("%d",s);return 0;}
		s++;
		int ss=s;
		while(ss!=0)
		{
			num[ss%10]++;
			ss/=10;
		}	
	}
}
