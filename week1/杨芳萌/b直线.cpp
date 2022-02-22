#include<bits/stdc++.h>
using namespace std;
const double X = 20.0;
const double Y = 21.0;
double cnt;
map<pair<double,double>,int> mp;

int main() {
	for(double a=0.0; a<X; a++) 
		for(double b=0.0; b<Y; b++) 
			for(double c=0.0; c<X; c++) 
				for(double d=0.0; d<Y; d++) {
					if(c==a||d==b) continue;
					double k = (a-c)/(b-d);
					double m = (c*b-d*a)/(c-a);
					if(mp[{k,m}]==0) { 
						mp[{k,m}] = 1;
						cnt++;
					}
				}
	cnt += X+Y;
	cout<<cnt<<endl; 
    return 0;
}
