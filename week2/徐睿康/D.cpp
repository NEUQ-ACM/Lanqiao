#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> >que;
vector<pair<int,int> >vec[3010];
long long dis[3010],pan[3010];
int gcd(int x,int y){
	return (y==0)?x:gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
void dij(int x){
	for(int i=1;i<=2021;i++)dis[i]=1e18;
	dis[x]=0;
	que.push(make_pair(0,x));
	while(que.size()){
		int u=que.top().second;
		que.pop();
		if(pan[u])continue;
		pan[u]=1;
		for(int i=0;i<vec[u].size();i++){
			int v=vec[u][i].first,w=vec[u][i].second;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				que.push(make_pair(-dis[v],v));
			}
		}
	}
}
int main(){
	for(int i=1;i<=2021;i++){
		for(int j=i+1;j<=i+21;j++){
			vec[i].push_back(make_pair(j,lcm(i,j)));
			vec[j].push_back(make_pair(i,lcm(i,j)));
		}
	}
	dij(1);
	cout<<dis[2021];
	return 0;
}
