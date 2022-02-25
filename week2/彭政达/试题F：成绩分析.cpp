#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long double a,maxm=0,minm=100,ave=0;
	for(int i=0;i<n;i++){
		cin>>a;
		ave+=a;
		if(maxm<a) maxm=a;
		if(minm>a) minm=a;
	}
	cout<<maxm<<endl<<minm<<endl<<setiosflags(ios::fixed) <<setprecision(2) ave/n<<endl;
}
