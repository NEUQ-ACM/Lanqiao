#include<bits/stdc++.h>
using namespace std;
int total;
bool jud[7];

void panduan(int n)
{
	if(!jud[n]) return ;
	jud[n]=0;
	total--;
	if(n==0)
	{
		panduan(1);
		panduan(5);
		
	}
	else if(n==1)
	{
		panduan(0);
		panduan(6);
		panduan(2);
		
	}
	else if(n==2)
	{
		panduan(1);
		panduan(6);
		panduan(3);
		
	}
	else if(n==3)
	{
		panduan(2);
		panduan(4);
		
	}
	else if(n==4)
	{
		panduan(3);
		panduan(6);
		panduan(5);
		
	}
	else if(n==5)
	{
		panduan(4);
		panduan(6);
		panduan(0);
		
	}
	else if(n==6)
	{
		panduan(5);
		panduan(1);
		panduan(2);
		panduan(4);
		
	}
}


int main()
{
	int ans=0;
	int t=2*2*2*2*2*2*2;
	
	for(int i=1;i<t;i++)
	{
		int ttt;
		int tt=i;
		total=0;
		for(int j=0;j<7;j++)
		{
			if(tt%2==1) 
			{
				ttt=j;
				jud[j]=1;
				total++;
			}
			else jud[j]=0;
			tt/=2;
		}
		panduan(ttt);
		if(!total) ans++;
	}
	cout<<ans;
	return 0;
}

//80
