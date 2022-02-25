#include <bits/stdc++.h>
using namespace std;
#define maxn 1000010

int a[maxn];
int maxx,sum,minn = 0x7fff,n;
double res;
int main(){
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>a[i];
		if(a[i] > maxx)maxx = a[i];
		if(a[i] < minn)minn = a[i];
		sum += a[i];
	}
	res = (double)sum / (double)n;
	cout<<maxx<<endl;
	cout<<minn<<endl;
	cout<<fixed<<setprecision(2)<<res<<endl;
	return 0;
}