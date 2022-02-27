#include<iostream>
using namespace std;

int main()
{
	int n,ans1=0,ans2=0;
	int a[10];
	cin>>n;
	for(int i=n+1;;i++)
	{
		int j=1;
		int tmp=i;
		while(j<=8)
		{
			a[j++]=tmp%10;
			tmp/=10;
		}
		bool flag=0;
		int m=a[5]*10+a[6],k=a[7]*10+a[8],y;
		switch(m)
		{
			case 4:
			case 6:
			case 9:
			case 11:
				if(m>30) flag=1;
				break;
			case 2:
				y=a[1]*1000+a[2]*100+a[3]*10+a[4];
				if((y%4==0&&y%100!=0)||y%400==0) {if(m>29) flag=1;break;}
				else {if(m>28) flag=1;break;}
			default:
				if(m>31) flag=1;
				break;	
		}
		if(flag)
			continue;
		if(a[1]==a[3]&&a[1]==a[6]&&a[1]==a[8]&&a[2]==a[4]&&a[2]==a[5]&&a[2]==a[7])
			for(int j=8;j;j--)
			{
				ans2*=10;
				ans2+=a[j];
			}
		if(a[1]==a[8]&&a[2]==a[7]&&a[3]==a[6]&&a[4]==a[5]&&!ans1)
			for(int j=8;j;j--)
			{
				ans1*=10;
				ans1+=a[j];
			}
		if(ans1&&ans2)
			break;	
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}

