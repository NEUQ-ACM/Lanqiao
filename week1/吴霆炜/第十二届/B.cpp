#include<bits/stdc++.h>
using namespace std;
#define maxn 2000000

int n;
struct point{
	double k;
	double b;
}l[maxn];

bool cmp(point a,point b){
	if(a.k!=b.k) return a.k<b.k;
	return a.b<b.b;
}
int main(){
	for(int x1=0;x1<20;x1++)
	for(int y1=0;y1<21;y1++)
	for(int x2=0;x2<20;x2++)
	for(int y2=0;y2<21;y2++)
	if(x1!=x2){
		double k=(double)(y2-y1)/(x2-x1);
		double b=y1-k*x1;
		l[n].k=k;
		l[n].b=b;
		n++;
	}
	sort(l,l+n,cmp);
	int ans=1;
	for(int i=1;i<n;i++){
		if(fabs(l[i].k-l[i-1].k)>1e-3||fabs(l[i].b-l[i-1].b)>1e-8){
			ans++;
		}
	}
	ans += 20;
	cout<<ans<<endl;
}
