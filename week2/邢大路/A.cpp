#include<bits/stdc++.h>
using namespace std;
bool judge(int a){
	while(a){
		int m=a%10;
		if(m==2||m==0||m==1||m==9)return 1;
		a/=10; 
	}
	return 0;
}
int main(){
	long long cnt=0;
	for(int i=1;i<=2019;i++){
		if(judge(i))cnt+=i*i;
	}
	cout<<cnt;
	return 0;
}
