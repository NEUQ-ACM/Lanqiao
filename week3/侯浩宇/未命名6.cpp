#include<bits/stdc++.h>
using namespace std;

int n,a[100],maxx=0,minn=1000;
double pj;

int main(){
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		pj+=a[i];
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
	}
	
	pj/=n;
	
	cout<<maxx<<endl<<minn<<endl;
	cout<<fixed<<setprecision(2)<<pj;
	
	return 0;
}
