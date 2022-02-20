#include <bits/stdc++.h>
using namespace std;
const int maxn=100052;
int fa[maxn],n;
vector<int> u[maxn];
int dfs(int x){
	int y=1;
	for (int i=0;i<u[x].size();i++){
		int temp=1+dfs(u[x][i])+u[x].size()-1;
		y=max(temp,y);
	}
	return y;
}
int main(){
	cin>>n;
	for(int i=0;i<n-1;i++){
		cin>>fa[i];
		u[fa[i]].push_back(i+2);
	}
	cout<<dfs(1)-1<<endl;
	return 0;
}
