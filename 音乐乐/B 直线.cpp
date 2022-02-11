//ans:40238
#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x,y;
};
vector<point>vec;
set< pair<double,double> >s;

int main()
{
	for(int i=0;i<20;i++)
		for(int j=0;j<21;j++)
			vec.push_back((point){i,j});
	int cap=vec.size();
	for(int i=0;i<cap;i++)
		for(int j=i+1;j<cap;j++)
		{
			double k=(vec[j].y-vec[i].y)*1.0/(vec[j].x-vec[i].x);
			double b=(vec[i].x*vec[j].y-vec[j].x*vec[i].y)*1.0/(vec[i].x-vec[j].x);
			s.insert(pair<double,double>(k,b));
		}
	cout<<s.size();
	return 0;
}
