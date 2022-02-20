#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[8];
	bool jud[2]={0,0};
	int tt;
	cin>>tt;
	int n=tt/10000;
	while(n)
	{
		int t=n;
		a[4]=t%10;t/=10;
		a[3]=t%10;t/=10;
		a[2]=t%10;t/=10;
		a[1]=t%10;
		int yue=a[4]*10+a[3];
		int ri=a[2]*10+a[1];
		if(n==tt/10000&&yue*100+ri<=tt%10000)
		{
			n++;
			continue;
		}
		if(!yue||!ri) 
		{
			n++;
			continue;
		}
		if(!jud[0])
		{
			if((ri<=31&&(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12))||(n%4==0&&ri<=29&&yue==2)||(n%4!=0&&ri<=28&&yue==2)||(ri<=30&&(yue==4||yue==6||yue==9||yue==11))) 
			{
				jud[0]=1;
				cout<<a[1]<<a[2]<<a[3]<<a[4]<<a[4]<<a[3]<<a[2]<<a[1]<<'\n';
			}
		}
		if(!jud[1])
		{
			if(ri<=12&&yue<=12&&ri==yue)
			{
				jud[1]=1;
				cout<<a[1]<<a[2]<<a[3]<<a[4]<<a[4]<<a[3]<<a[2]<<a[1];
			}
		}
		if(jud[1]&&jud[0]) break;
		n++;
	}
	return 0;
} 
