1.
8.795
ДњТыЃК
#include<iostream>
#include<math.h>
using namespace std;
double lenth(double x1,double y1,double x2,double y2);
double heron(double l1,double l2,double l3);
int main()
{
	double x1=2.3,y1=2.5;
	double x2=6.4,y2=3.1;
	double x3=5.1,y3=7.2;
	double l1=lenth(x1,y1,x2,y2);
	double l2=lenth(x1,y1,x3,y3);
	double l3=lenth(x2,y2,x3,y3);
	double area=heron(l1,l2,l3);
	printf("%.3lf",area);
	return 0;
}
double lenth(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double heron(double l1,double l2,double l3)
{
	double p=(l1+l2+l3)/2;
	return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}

2.
160225
ДњТыЃК
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	const int n=12;
	for(int people=1;people>=1;people++)
	{
		int cnt=0;
		for(int i=1;i*i*2<=people;i++)
		{
			int j=people-i*i;
			int temp=sqrt(j);
			if(temp*temp==j)
			{
				cnt++;
			}
		}
		if(cnt==n)
		{
			cout<<people;
			break;
		}
	}
	return 0;
}

3.
balance(data[a],data[std])

4.
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> num(n);
	for(int i=0;i<n;i++)
	{
		num[i]=i+1;
	}
	int x=0;
	while (1) 
	{
		x=(x+k-1)%num.size();
		num.erase(num.begin()+x);
		if (num.size() == 1)
		{
			cout << num[0] << endl;
			break;
		}
	}
	return 0;
}

5.
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1000010;
int g[N];
int main() 
{
	ll n;
	cin>>n;
	g[1]=1,g[2]=2;
	int k=2;
	for(int i=2;i>=2;i++)
	{
		for(int j=1;j<=g[i];j++)
		{
			if(k<N)
			{
				g[k]=i;
				k++;
			}
			else goto stop;
		}
	}
	stop:;
	ll s=0,t=0;
	for(int i=1;i<N;i++)
	{
		s=s+i*(ll)g[i];
		if(s>=n) 
		{
			s=s-i*(ll)g[i];
			cout<<t+(n-s+i-1)/i<<endl;
			break;
		}
		t=t+g[i];
	}
	return 0;
}
