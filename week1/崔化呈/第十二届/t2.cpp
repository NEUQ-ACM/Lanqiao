#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x;
	int y;
};
int main()
{
	vector<point> p;
	for(int i=0;i<=19;i++)
	{
		for(int j=0;j<=20;j++)
		{
			p.push_back({i,j});
		}
	}
	int pn=p.size();
	set<pair<double,double> >lines;
	for(int i=0;i<pn;i++)
	{
		for(int j=0;j<pn;j++)
		{
			if(p[i].x!=p[j].x&&p[i].y!=p[j].y)
			{
				double k=(p[i].y-p[j].y)*1.0/(p[i].x-p[j].x);
				double b=((p[i].y*(p[i].x-p[j].x)-(p[i].y-p[j].y)*p[i].x)*1.0)/(p[i].x-p[j].x);
				lines.insert({k,b});
			}
		}
	}
	printf("%d",21+20+lines.size());
	return 0;
} 
