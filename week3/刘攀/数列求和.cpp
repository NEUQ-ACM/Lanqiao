#include<bits/stdc++.h>
using namespace std;
int a[20202020];
int main(){
	a[1]=1;
	a[2]=1;
	a[3]=1;
	a[4]=3;
	for(int i=5;i<=20190324;i++){
		a[i]=(a[i-1]+a[i-2]+a[i-3])%10000;
	}
	cout<<a[20190324];
}
