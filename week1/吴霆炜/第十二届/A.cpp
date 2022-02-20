#include <bits/stdc++.h>
using namespace std;

int temp = 0;
int sum[10];
bool work(int x){
	while(x){
		int t = x % 10;
		x /= 10;
		if(!sum[t])return false;
		sum[t]--;
	}
	return true;
}
int main(){
	for(int i = 0;i < 10;i++)
	sum[i] = 2021;
	while(work(++temp)){}
	temp--;
	cout<<temp<<endl;
	return 0;
}