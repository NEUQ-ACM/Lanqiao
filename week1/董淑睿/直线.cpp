#include <bits/stdc++.h>
#define _ 1000005
using namespace std;
struct node {int x,y;};
int main() {
	vector<node> p;
	for(int i=0;i<=19;++i)
		for(int j=0;j<=20;++j)
			p.push_back({i, j});
	int len=p.size();
	set<pair<double,double>> lines; 
	for(int i=0;i<len;++i) {
		for(int j=0;j<len;++j) {
			if(p[i].x!=p[j].x&&p[i].y!= p[j].y)  {
				double k=(p[j].y-p[i].y)*1.0/(p[j].x-p[i].x);
				double b=(p[j].y*(p[j].x-p[i].x)-(p[j].y-p[i].y)*p[j].x)*1.0/(p[j].x-p[i].x);
				lines.insert(pair<double,double>(k,b));
			}
		}
	}
	cout<<lines.size()+41<<"\n"; 
	return 0;
}