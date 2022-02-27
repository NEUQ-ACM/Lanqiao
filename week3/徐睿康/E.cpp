#include<bits/stdc++.h>
using namespace std;

int main(){
	long long ans=1;
	for(int i=2;i<=20;i++){
		ans+=2;
		ans+=2*(i-2);
	}
	ans*=40;
	for(int i=1;i<=20;i++){
		ans+=i;
	}
	ans+=40;
	cout<<ans;
	return 0;
}
