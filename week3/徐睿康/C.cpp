#include<bits/stdc++.h>
using namespace std;
int flag;
void dfs(int cnt,int x,int y,int pan){
	if(x==20&&y==20){
		flag=cnt;
		return;
	}
	if(pan==1){
		if(y!=1)dfs(cnt+1,x+1,y-1,pan);
		else dfs(cnt+1,x+1,y,-pan);
	}
	else{
		if(x!=1)dfs(cnt+1,x-1,y+1,pan);
		else dfs(cnt+1,x,y+1,-pan);
	}
}
int main(){
	dfs(1,1,1,1);
	cout<<flag;
	return 0;
}
