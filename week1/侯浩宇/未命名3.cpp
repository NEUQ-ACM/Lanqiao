#include<bits/stdc++.h>
using namespace std;

long long n,ans=0;

void f2(long long x){
	for(long long i=1;i<=x;i++){
		if(x%i==0){
			ans++;
		}
	}	
}

void f3(long long x){
	for(long long i=1;i<=x;i++){
		if(x%i==0){
			f2(x/i);
		}
	}
}

int main(){
/*	n=2021041820210418;
	f3(n);
	cout<<ans;*/
	
	cout<<2430;
	
	return 0;
}
