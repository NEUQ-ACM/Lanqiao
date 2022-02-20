#include<bits/stdc++.h>
using namespace std;
int main(){
	int sum=0,f[10001],n;
	double ave;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		sum+=f[i];
	}
	sort(f+1,f+n+1);
	ave=sum*1.0/n;
	cout<<f[n]<<endl;
	cout<<f[1]<<endl;
	printf("%.2f",ave);
	return 0;
}
