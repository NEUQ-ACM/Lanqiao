#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int edge[2030][2030];
int visit[2030];
int path[2030];
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int lcm(int x,int y){
	return x/gcd(x,y)*y;
}
int main(){
	memset(edge,INF,sizeof(edge));
	for(int i=1;i<=2021;i++){
		for(int j=i+1;j<=2021;j++){
			if(j-i>21) continue;
			int cost=lcm(i,j);
			edge[i][j]=cost;
			edge[j][i]=cost;
		}
	}
	memset(visit,0,sizeof(visit));
	memset(path,INF,sizeof(path));
	path[1]=0;
	for(int i=1;i<=2021;i++){
		int start;
		int minn=INF;
		for(int j=1;j<=2021;j++){
			if(!visit[j]&&path[j]<=minn){
				minn=path[j];
				start=j;
			}
		}
		visit[start]=1;
		for(int j=1;j<=2021;j++){
			path[j]=min(path[j],path[start]+edge[start][j]);
		}
	}
	cout<<path[2021];
}
