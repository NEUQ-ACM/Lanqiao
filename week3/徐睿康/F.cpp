#include<bits/stdc++.h>
using namespace std;
double sum=0;
int maxx=-1,minn=1e9,n,a[10010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]>maxx)maxx=a[i];
		if(a[i]<minn)minn=a[i];
	}
	cout<<maxx<<endl<<minn<<endl;
	printf("%.2lf\n",sum/n);
	return 0;
}
