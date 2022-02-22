#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y);
int lcm(int x,int y); 
int dis[3000];
int main()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	for(int i=1;i<=2021;i++)
	{
		for(int j=i+1;j<=2021 && j-i<=21;j++)
		{
		dis[j]=min(dis[j],lcm(i,j)+dis[i]);	
		}
		
		
		
	}
		
	 cout<<dis[2021];
}
int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
} 
