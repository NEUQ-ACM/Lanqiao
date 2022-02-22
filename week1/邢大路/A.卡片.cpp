#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10];
	int ans=0;
	for(int i=0;i<=9;i++)a[i]=2021;
	for(int i=0;i<=10000000;i++){
		int flag=1;
		int num=i;
		while(num){
			int b=num%10;
			if(!a[b])flag=0;
			a[b]--;
			num=num/10;
		}
		if(flag)ans=i;
		else break;
	}
	cout<<ans;
	return 0;
} 
