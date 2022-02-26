#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int ans=0;
	int n=39;
	
	for(int i=1;i<=n;i++){
		ans+=i;
	}
	
	cout<<(ans*2-n)/2;
	
	return 0;
}
//760
