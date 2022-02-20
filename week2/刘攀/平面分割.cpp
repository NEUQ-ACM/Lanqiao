#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=20;
	int m=20;
	int ans=1;
	for(int i=1;i<=20;i++){
		ans+=i;
	}
	for(int i=1;i<=20;i++){
		ans+=n*2+2*(i-1);
	}
	cout<<ans<<endl;
}
