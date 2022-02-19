#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
bool judge(int x,int y){
	if(gcd(x,y)==1) return true;
	return false;
}
int main(){
	int sum=0;
	for(int i=1;i<=2020;i++){
		for(int j=1;j<=2020;j++){
			if(judge(i,j)){
				sum++;
			}
		}
	}
	cout<<sum<<endl;
}
