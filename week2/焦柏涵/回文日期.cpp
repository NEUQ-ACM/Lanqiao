#include <bits/stdc++.h>
using namespace std;
string s;
void huiwen(vector <int> a,int num,int p1,int p2,int p3)
{
	int t=p1;
	if(p2>=p3) t++;
	cout<<t;
	while(t)
	{
		cout<<t%10;t/=10;
	}
	cout<<endl;
	int d=p1/100;
	if(d%10==d/10) d++;
	int sum1=p1*10000+p2;
	int sum2=d*1010000+(d%10*10+d/10)*101;
	if(sum2<=sum1)
	{
		d++;
		if(d%10==d/10) d++;
		sum2=d*1010000+(d%10*10+d/10)*101;
	}
	cout<<sum2;
}
int main()
{
	int num,p1,p2,p3;
	vector <int> a;
	cin>>s;
	for(int i=0;i<s.size();i++) a.push_back(s[i]-'0');
	num=a.size();
	p1=1000*a[0]+100*a[1]+10*a[2]+a[3];
	p2=1000*a[4]+100*a[5]+10*a[6]+a[7];
	p3=1000*a[3]+100*a[2]+10*a[1]+a[0];
	huiwen(a,num,p1,p2,p3);
	return 0;
}
