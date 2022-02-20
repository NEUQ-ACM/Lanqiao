#include<bits/stdc++.h>
using namespace std;
int a[100];
int main(){
	int n;
	cin>>n;
	double sum=0;
	int maxn=0;
	int minn=100000;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
		if(maxn<a[i]) maxn=a[i];
		if(minn>a[i]) minn=a[i];
	}
	cout<<maxn<<endl;
	cout<<minn<<endl;
	cout<<fixed;
	cout<<setprecision(2);
	cout<<sum/n<<endl;
}
