//100
#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
string s;
ll ans1,ans2;
int v1,v2;
bool run(int y)
{
	if(y%4==0&&y%100!=0||y%400==0)return true;
	return false;
}
bool hui(int y,int m,int d)
{
	if(y%10!=m/10)return false;
	if(y%100/10!=m%10)return false;
	if(y%1000/100!=d/10)return false;
	if(y/1000!=d%10)return false;
	return true;
}
bool tehui(int y,int m,int d)
{
	int a[10];
	a[1]=y/1000;a[2]=y%1000/100;a[3]=y%100/10;a[4]=y%10;
	a[5]=m/10;a[6]=m%10;a[7]=d/10;a[8]=d%10;
	if(a[1]==a[3]&&a[3]==a[6]&&a[6]==a[8]&&a[2]==a[4]&&a[4]==a[5]&&a[5]==a[7])
	{
		return true;
	}
	return false;
}
//0是平年,1是闰年 
int days[2][15]=
{
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};
int main()
{
	cin>>s;
	int year=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
	int month=(s[4]-'0')*10+s[5]-'0';
	int day=(s[6]-'0')*10+s[7]-'0';
	while(1)
	{
		int now;
		if(run(year))now=1;
		else now=0;
		day++;
		if(day>days[now][month])
		{
			day=1;
			month++;
		}
		if(month>12)
		{
			month=1;
			year++;
		}
		if(hui(year,month,day)&&v1==0)
		{
			ans1=year*10000+month*100+day;
			v1=1;
		}
		if(tehui(year,month,day)&&v2==0)
		{
			ans2=year*10000+month*100+day;
			v2=1;
		}
		if(v1==1&&v2==1)break;
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}
