#include<bits/stdc++.h>
using namespace std;
struct point
{
	int x;
	int y;
};
vector<point> P;
set<pair<double, double> > L;

int main(void)
{
	for(int i=0; i<20; i++)
		for(int j=0; j<21; j++)
			P.push_back({i, j});
	
	int p_n=P.size();
	for(int i=0; i<p_n; i++)
		for(int j=0; j<p_n; j++)
			if(P[i].x!=P[j].x && P[i].y!=P[j].y)
			{
				double k= (P[i].y-P[j].y)*1.0/(P[i].x-P[j].x);
				double b= (P[i].y*(P[i].x-P[j].x)*1.0-P[i].x*(P[i].y-P[j].y)*1.0)/(P[i].x-P[j].x);
				L.insert({k, b});
			}
	cout<<L.size()+41;
	
	return 0;
}