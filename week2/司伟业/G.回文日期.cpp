#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#define clean(x) memset(x,0,sizeof(x))
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}
int m[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int check1(int x,int y,int z)
{
	if(x/1000==z%10&&x/100%10==z/10&&x/10%10==y%10&&x%10==y/10) return 1;
	return 0;
}
int check2(int x,int y,int z)
{
	if(x/1000==z%10 && x/100%10==z/10 && x/10%10==y%10 && x%10==y/10 && z%10==y%10 && z/10==y/10) return 1;
	return 0;
}
int main()
{
	int n=read(),pd1=0,pd=0,cnt1=0,cnt2=0;
	for(int year=n/10000;year<=9090;year++){
		for(int month=(pd?1:(n/100%100));month<=12;month++){
			for(int day=(pd1?1:(n%100+1));day<=m[month];day++){
				if(!cnt1&&check1(year,month,day)) {
					cnt1=1;
					printf("%d%02d%02d\n",year,month,day);
				}
				if(!cnt2&&check2(year,month,day)){
					cnt2=1;
					printf("%d%02d%02d\n",year,month,day);
				}
				if(cnt1&&cnt2) return 0;
			}
			pd1=1;
		}
		pd=1;
	}
}
