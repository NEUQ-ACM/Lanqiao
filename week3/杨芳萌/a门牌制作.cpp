#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
	for(int i=1; i<=2020; i++) {
		int tmp = i;
		while(tmp) {
			if(tmp%10==2) cnt++;
			tmp /= 10;
		}
	}
	cout<<cnt<<endl;
    return 0;
}

