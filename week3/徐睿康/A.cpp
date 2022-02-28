#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void work(int x){
	while(x){
		if(x%10==2)cnt++;
		x/=10;
	}
}
int main(){
	for(int i=1;i<=2020;i++){
		work(i);
	}
	cout<<cnt;
	return 0;
}
