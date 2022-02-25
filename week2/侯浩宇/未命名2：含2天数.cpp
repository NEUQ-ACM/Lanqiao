#include<bits/stdc++.h>
using namespace std;

int ans=0;

bool rn(int year){
	if(year%400==0){
		return 1;
	}
	else{
		if(year%4==0&&year%100){
			return 1;
		}
			
		else{
			return 0;
		}
	}
}

void pd(int year){
	
	string y=to_string(year);
	bool p=0,p2=0;
	
	p=rn(year);
	for(int i=0;i<y.length();i++){
		if(y[i]=='2'){
			p2=1;
			
			break;
		}
	}
	
	if(p2){
		if(p)
		ans+=366;
		else 
		ans+=365;
		return;
	}
	
	ans+=179;
	if(p)
	ans++;
	return;
	
}

int main(){
	
	for(int i=1900;i<=9999;i++){
		pd(i);
	}

	cout<<ans; 
	
	return 0;
}//1994240
