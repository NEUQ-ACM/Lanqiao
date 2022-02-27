#include <bits/stdc++.h>
using namespace std;

int cnt;
int gcd(int x,int y){
	if(x % y == 0)
	return y;
	else 
	return gcd(y,x % y);
}

int main(){
	for(int i = 1;i <= 2020;i++){
		for(int j = 1;j <= 2020;j++){
			if(gcd(i,j) == 1)cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}