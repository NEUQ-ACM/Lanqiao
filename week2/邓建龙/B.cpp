#include<bits/stdc++.h>
using namespace std;
int sum;
int gcd(int x, int y){
	if(y == 0) return x;
	return gcd(y, x % y);
}
bool judge(int x, int y){
	if(gcd(x, y) == 1) return true;
	return false;
}
int main(){
	for(int i = 1; i < 2021; i++) {
		for(int j = 1; j < 2021; j++) {
			if(judge(i, j)) sum++;
		}
	}
	cout<< sum <<endl;
}