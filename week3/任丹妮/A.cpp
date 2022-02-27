#include <bits/stdc++.h>
using namespace std;
int a[10];
bool f(int n){
	int r;
	while(n){
		r=n%10;
		if(a[r]==0) return false;
		else a[r]--;
		n/=10;
	}
	return true;
}
int main(){
	for(int j=0;j<10;j++){
		a[j]=2021;
	}
	int i=0;
	for(i=1;;i++){
		if(f(i)) continue;
		else break;
	}
	cout<<i-1<<endl;
} 
