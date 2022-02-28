#include<bits/stdc++.h>
using namespace std;
int pyu[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check1(int n)
{
	while(n)
	{
		if(n%10==2){return 1;}
		n/=10;
	}
	return 0;
}
int main()
{
	int ans=0;
	bool p=0;
	for(int i=1900;i<=9999;i++)
	{
		if((i%4==0&&i%100!=0)||i%400==0){p=0;pyu[2]=29;}
		else{p=1;pyu[2]=28;}
		if(check1(i))
		{
			if(p==0){ans+=366;}
			else{ans+=365;}
			continue;
		}
		for(int j=1;j<=12;j++)
		{
			if(j==2||j==12){ans+=pyu[j];continue;}
			for(int k=1;k<=pyu[j];k++)
			{
				if(check1(k)){ans++;}
			}
		}
	}
	printf("%d",ans);
}
