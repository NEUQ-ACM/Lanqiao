#include<bits/stdc++.h>
using namespace std;
bool flag(int year){
	 if((year%4== 0) && ( (year%100)!=0 ) || year%400==0)	return true;
	 else	return false;
}
bool f(int year){
	while(year!=0){
		if(year%10==2){
			return true;
		}
		year/=10;
	}
	return false;
}
int main(){
	int ans=0;
	for(int i=1900;i<=9999;i++){
		if(f(i)&&flag(i))	ans=ans+366;
		else if(f(i)&&!flag(i))	ans=ans+365;
		else if(!f(1)&&flag(i))	ans=ans+180;
		else ans+=179;
	}
	cout<<ans;
	return 0;
}
