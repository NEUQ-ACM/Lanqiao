#include<bits/stdc++.h>
using namespace std;
int a[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};//闰年366
int b[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//平年365
bool run(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)//闰年
	{
		return 1;
	}
	else return 0;//平年
}
string tostr(int t)
{
	string s;
	while(t)
	{
		s+=t%10+'0';
		t=t/10;
	}//得到反的字符串
	reverse(s.begin(),s.end());//反转
	return s;
}
int hui(int y,int m,int d)
{
	//string ys=to_string(y),ms=to_string(m),ds=to_string(d);//数字转字符串
	
	string ys=tostr(y),ms=tostr(m),ds=tostr(d);//数字转字符串
	reverse(ys.begin(),ys.end());//反转年份
	//for(int i=ys.length();i<4;i++) ys+="0";
	for(int i=ms.length();i<2;i++) ms="0"+ms;
	for(int i=ds.length();i<2;i++) ds="0"+ds;
	if(ys==ms+ds)//回文
	{
		string BA=ys.substr(0,2);
		if(BA==ys.substr(0,2)&&BA==ms&&BA==ds) return 2;//ABABBABA型
		else return 1;
	}
	else return 0;
}
int main()
{
	int x;
	cin>>x;
	int y,m,d;
	y=x/10000;
	m=x/100%100;
	d=x%100;
    bool f1=0,f2=0;
	while(f1==0||f2==0)
	{
		if(run(y))//闰年
		{
			d++;
			if(d>a[m])//大于一个月的最后一天
			{
				d=1;
				m++;
			}
		}
		else
		{
			d++;
			if(d>b[m])//大于一个月的最后一天
			{
				d=1;
				m++;
			}
		}
		if(m>12)//月份超12
		{
			m=1;
			y++;
		}
		//以上为处理日期进位
		if(hui(y,m,d)>0)//回文
		{
			if(f1==0) printf("%04d%02d%02d\n",y,m,d);
			f1=1;
			if(hui(y,m,d)==2)//ABABBABA
			{
				printf("%04d%02d%02d\n",y,m,d);
				f2=1;
			}
		}
	}
	
    return 0;
}
