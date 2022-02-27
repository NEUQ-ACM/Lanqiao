#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[22];
	a[1]=1;
	a[2]=5;
	for(int i=3;i<=20;i++){
		a[i]=a[i-1]+4+a[i-1]-a[i-2];
	}
	cout<<a[20];
	return 0;
}
