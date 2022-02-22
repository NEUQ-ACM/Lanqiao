#include<bits/stdc++.h>
using namespace std;

int ans=0;

void f(int x){
	while(x){
		if(x%10==1)
		ans++;
		x/=10;
	}
}



void f2(int x){
	string strInt = std::to_string(x);
	for(int i=0;i<strInt.length();i++){
		if(strInt[i]=='1') ans++;
		
	}
}


int main(){
	
	int i=0;
	while(++i){
	//	f(i);
	f2(i);
		if(i==3099)
		cout<<ans;
	}
	return 0;
}
