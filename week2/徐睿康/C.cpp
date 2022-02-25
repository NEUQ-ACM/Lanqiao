#include<bits/stdc++.h>
using namespace std;
long long cnt=0;
void dfs(int x,int ceng){
	if(ceng==2){
		cnt++;
		return;
	}
	for(int i=1;i<=x;i++){
		if(x%i==0){
			dfs(x/i,ceng+1);
		}
	}
}
int main(){
	long long x=2021041820210418;
	dfs(x,0);
	cout<<cnt;
	return 0;
}
