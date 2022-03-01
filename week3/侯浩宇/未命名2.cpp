#include<bits/stdc++.h>
using namespace std;

bool hz(int a,int b){
	for(int i=2;i<=min(a,b);i++){
		if(a%i==0&&b%i==0)
		
		return 0;
	}
	return 1;
}

int main(){
	
	int ans=0;
	
	for(int i=1;i<=2020;i++){
	for(int j=1;j<i;j++){
		ans+=hz(i,j);
	//	cout<<i<<"   "<<j<<endl;
	}		
	}

	cout<<ans*2+1;
	
	return 0;
}
//2481215
