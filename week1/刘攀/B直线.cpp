#include<bits/stdc++.h>
using namespace std;
struct node{
	double k;
	double b;
};
bool cmp(node a,node b){
	if(a.k!=b.k) return a.k<b.k;
	else return a.b<b.b;
}
int n=0;
node l[2000000];
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
	int sum=1;
	for(int i=1;i<n;i++){
		if(fabs(l[i].k-l[i-1].k)>1e-3||fabs(l[i].b-l[i-1].b)>1e-8){
			sum++;
		}
	}
	cout<<sum+20<<endl;
}
