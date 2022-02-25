#include <bits/stdc++.h>
using namespace std;
int main(){
	int a[50][50]={0},x=1,y=1,f=1;
	while(a[20][20]==0){
		x++;f++;
		while(x!=1){
			x--;y++;
			a[x][y]=++f;
		}
		y++;f++;
		while(Y!=1){
			x++;y--;
			a[x][y]=++f;
		}
	}
	cout<<a[20][20]<<endl;
}
