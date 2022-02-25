#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> pdd;
set<pdd> m;//´æĞ±ÂÊkºÍ½Ø¾àb
const int N=30;
pdd point[N*N];
#define x first
#define y second
int main(){
	int cnt=0;
	for(int i=0;i<20;i++){
		for(int j=0;j<21;j++){
			point[cnt].x=i;
			point[cnt].y=j;
			cnt++;
		}
	}
	int ans=20+21;
	for(int i=0;i<cnt;i++){
		for(int j=0;j<cnt;j++){
			if(point[i].x==point[j].x||point[i].y==point[j].y)
				continue;
			double k=(point[j].y-point[i].y)/(point[j].x-point[i].x);
			double b=(point[j].x*point[i].y-point[j].y*point[i].x)/(point[j].x-point[i].x);
			m.insert({k,b});
		}
	}
	for(auto it=m.begin();it!=m.end();it++)
        ans++;
	cout<<ans<<endl;
}
//40257


