#include <bits/stdc++.h>
using namespace std;

int cnt,n = 1;
int main(){
	while(n != 2021){
		int temp = n;
		while(temp){
			int r = temp % 10;
			if(r == 2)cnt++;
			temp /= 10;
		}
		n++;
	}
	cout<<cnt<<endl;
	return 0;
}