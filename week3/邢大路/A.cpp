#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans=0;
	for(int i=1;i<=2020;i++){
		int num=i;
		while(num){
			if(num%10==2)ans++;
			num=num/10;
		}
	}
	cout<<ans;
}
