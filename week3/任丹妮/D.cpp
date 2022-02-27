#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int maxsize=1e5+10;
struct {
	int vexnum,arcnum;
	int arcs[maxsize][maxsize];
}G;
int visit[2021];
int dis[2021];
int gcd(int a,int b){
	int sum=a*b;
	int r=a%b;
	while(r){
		a=b;
		b=r;
		r=a%b;
	}
	return sum/b;
}
void dijkstra(int s,int e){
	int i,j,u;
	int min=INF;
	for(i=0;i<G.vexnum;i++){
		dis[i]=G.arcs[s][i];
		visit[i]=0;
	}
	visit[s]=1;
	for(i=0;i<G.vexnum;i++){
		min=INF;
		for(j=0;j<G.vexnum;j++){
			if(!visit[j]&&dis[j]<min){
				min=dis[j];
				u=j;
			}
		}
		visit[u]=1;
		for(j=0;j<G.vexnum;j++){
			if(!visit[j]&&dis[j]>dis[u]+G.arcs[u][j]){
				dis[j]=dis[u]+G.arcs[u][j];
			}
		}
	}
	printf("%d",dis[e]);
}
int main(){
	G.vexnum=2021;
	G.arcnum=0;
	for(int i=0;i<2021;i++){
		for(int j=0;j<2021;j++){
			if(i==j) G.arcs[i][j]=0;
			else if(abs(i-j)<=21){
				G.arcs[i][j]=gcd(i+1,j+1);
				G.arcnum++;
			}
			else G.arcs[i][j]=INF;
		}
	}
	dijkstra(0,2020);
}
