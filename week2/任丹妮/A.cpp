#include <bits/stdc++.h> 
using namespace std;
int f(int n){
	int cnt=0;
	while(n){
		int r=n%10;
		n/=10;
		if(r==2) cnt++;
	}
	return cnt;
}
int main(){
	int ans=0;
	for(int i=1;i<2021;i++){
		ans+=f(i);
	}
	cout<<ans<<endl;
}
	
