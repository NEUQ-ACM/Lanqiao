#include<bits/stdc++.h>
using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//存储每个月的天数 

int isLeapYear(int y)//判断是否是闰年 
{
	if((y%4==0&&y%100!=0)||y%400==0)  return 1;//表示是闰年 
	return 0;
}

bool Hui(int t) //判断t是否是回文
{
	int i;//循环变量
	int temp;//中间变量
	char arr[10];
	memset(arr,0,sizeof(arr));
	temp=t;i=0;
	while(temp){
		arr[i++]=temp%10+'0';
		temp=temp/10;
	}
	for(i=0;i<4;i++){
		if(arr[i]!=arr[7-i])  return false;
	}
	return true;
} 

bool IsABHui(int t) //判断t是否是回文
{
	int i;//循环变量
	int temp;//中间变量
	char arr[10];
	memset(arr,0,sizeof(arr));
	temp=t;i=0;
	char a,b;
	while(temp)
    {
		arr[i++]=temp%10+'0';
		temp=temp/10;
	}
	a=arr[0];b=arr[1];
	if(a==b)  return false;
	for(i=0;i<4;i++){
		if(arr[i]!=arr[7-i])  return false;
		if(i%2==0&&arr[i]!=a)  return false;
		if(i%2!=0&&arr[i]!=b)  return false;  
	}
	return true;
}

bool illgle(int y,int m,int d)//判断日期是否合法 
{
	if(m<=0||d<=0||m>12||d>31)  return false;//表示不合法 
	if(m==2)
    {//2月份特殊处理 
		if(d>(day[m]+isLeapYear(y)))  return false;
	} 
	else
	{
		if(d>day[m])	return false;
	}
	return true;
} 

int main()
{
	int N;//表示输入的回文日期
	int t;//表示中间的日期 
	bool flag=true,glag=true;//标识 
	int r1,r2;//存储结果的两个日期 
	int y,m,d;//表示提取出来的年月日 
	cin>>N;
	t=N+1;
	while(flag||glag){
		y=t/10000;m=t%10000/100;d=t%100;
		if(illgle(y,m,d)){//判断该日期是否合法 
			if(Hui(t)){
				if(flag)
                {
					flag=false;r1=t;
				}
				if(IsABHui(t)&&glag){
					glag=false;r2=t;
				}
			}
		}
		t++;
	}
	cout<<r1<<endl;
	cout<<r2<<endl;
	return 0;
}




