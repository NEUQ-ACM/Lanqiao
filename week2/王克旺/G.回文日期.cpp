#include<bits/stdc++.h>
using namespace std;
int n,y[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int print(int x)
{
    int a[5],tmp=x,m=1;
    for(int i=1;i<=4;i++)
    {
    	a[i]=tmp%10;
		tmp=tmp/10;
	}       
    x=x*10000;
    for(int i=4;i>=1;i--)
    {
    	x=x+m*a[i];
		m=m*10;
	}       
    if(x<=n)
	{
		return 0;
	}
    cout<<x<<endl;
    return 1;
}
int date1(int x)
{
    int month=(x%10)*10+(x/10)%10;
    int day=((x/100)%10)*10+(x/1000);
    if(month<=0||month>=13)
	{
		return 0;
	}
    if(month==2&&((x%100!=0&&x%4==0)||(x%400==0)))
    {
        if(day<=29)
		{
			return 1;
		}
        return 0;
    }
    else if(day<=y[month]&&day>=1)
	{
		return 1;
	}
    return 0;
}
int date2(int x)
{
    if(date1(x)==0)
	{
		return 0;
	}
    int a=(x/10)%10,b=x%10;
    if(x/1000==a&&((x/100)%10)==b)
	{
		return 1;
	}
    return 0;
}
void ans(int x)
{
    for(int i=x;i<=9999;i++)
    {
    	if(date1(i))
		{
            if(print(i)==0)
			{
				continue;
			}
            break;
        }
	}       
    for(int i=x;i<=9999;i++)
    {
    	if(date2(i))
		{
            if(print(i)==0)
			{
				continue;
			}
            break;
        }
	}     
}
int main()
{
    cin>>n;
    ans(n/10000);
    return 0;
}
