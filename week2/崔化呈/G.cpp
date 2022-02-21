#include <bits/stdc++.h>
using namespace std;
int md[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //0229无需考虑 
int date1[10001],date2[10001],cnt1=0,cnt2=0;
void check(int n)
{
	int a=n/1000;
	int b=n/100%10;
	int c=n/10%10;
	int d=n%10;
	int mm=d*10+c;
	int dd=b*10+a;
	if(mm==0||mm>=13){return;}
	if(dd>md[mm]){return;}  //dd不会为0
	int t=n*10000+d*1000+c*100+b*10+a;
	date1[cnt1++]=t;
	if(a==c&&b==d){date2[cnt2++]=t;}
	return;
}
int main()
{
	for(int i=1001;i<=8999;i++)
	{
		check(i);
	}
	int nn;
	scanf("%d",&nn);
	int pos1=upper_bound(date1,date1+cnt1,nn)-date1;
	int pos2=upper_bound(date2,date2+cnt2,nn)-date2;
	printf("%d\n%d\n",date1[pos1],date2[pos2]);
	return 0;
}
