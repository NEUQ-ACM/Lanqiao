#include<bits/stdc++.h>
using namespace std;

bool heshu(int x){
	int n=0;
	for(int i=2;i<x;i++){
		if(x%i==0){
//			cout<<"x:"<<x<<" i:"<<i<<endl;
			return 1;
		}
	}
	return 0;
}

int ans=0;

int main(){
	
	for(int i=1;i<=2020;i++){
		if(heshu(i))
			ans++;	
	}
	
	cout<<ans;
	
	return 0;
}
//1713 
