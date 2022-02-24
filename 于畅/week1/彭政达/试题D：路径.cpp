#include <bits/stdc++.h>
using namespace std;
const int maxn=2021;
vector<int> u[maxn+52],v[maxn+52];
int disDijk[maxn+52];
bool visited[maxn+52];
void InitGroup(){
	for(int i=1;i<= maxn;i++){
		for(int j=i+1;j<=maxn;j++){
			if(j-i<=21){
				u[i].push_back(j);
				v[i].push_back(i*j/__gcd(i,j));
				u[j].push_back(i);
				v[j].push_back(i*j/__gcd(i,j));
			}
		}
	}
}
void Dijkstra(){
	memset(disDijk,0x3f,sizeof(disDijk));
	memset(visited,0,sizeof(visited));
	disDijk[1]=0;
	for (int i=1;i<=maxn;i++){
		int curMin=0x3f3f3f3f;
		int curIndex=-1;
		for (int j=1;j<=maxn;j++){
			if(visited[j]) continue;
			if(curMin>disDijk[j] || curIndex==-1){
				curMin=disDijk[j];
				curIndex=j;
			}
		}
		visited[curIndex] = true;
		for (unsigned int j=0;j<u[curIndex].size();j++){
			int t=u[curIndex][j],val=v[curIndex][j];
			disDijk[t]=min(disDijk[t],disDijk[curIndex]+val);
		}
	}
	cout<<disDijk[2021];
}
int main(){
	InitGroup();
	Dijkstra();
	return 0;
}
