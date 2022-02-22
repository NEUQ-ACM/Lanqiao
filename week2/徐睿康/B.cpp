#include<bits/stdc++.h>
using namespace std;
set<pair<double,double>>a;
void work(int x,int y,int xx,int yy){
	double k=(y-yy)/(x-xx);
	double b=y-(k*x);
	a.insert(make_pair(k,b));
}
int main(){
	for(int i=0;i<20;i++){
		for(int j=0;j<21;j++){
			for(int i1=0;i1<20;i1++){
				for(int j1=0;j1<21;j1++){
					if(i!=i1&&j!=j1){
						work(i,j,i1,j1);
					}
				}
			}
		}
	}
	cout<<a.size();
	return 0;
}
