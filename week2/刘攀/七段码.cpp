#include<bits/stdc++.h>
using namespace std;
int ans=0;
int maps[10][10];
int fa[10];
int vis[10];
int find(int i){
	if(fa[i]==i) return i;
	return fa[i]=find(fa[i]);
}
void dfs(int k){
	if(k>7){
		for(int i=1;i<=7;i++){
			fa[i]=i;
		}
		for(int i=1;i<=7;i++){
			for(int j=1;j<=7;j++){
				if(maps[i][j]&&vis[i]&&vis[j]){
					int fx=find(i);
					int fy=find(j);
					if(fx!=fy){
						fa[fx]=fy;
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=7;i++){
			if(fa[i]==i&&vis[i]){
				cnt++;
			}
		}
		if(cnt==1) ans++;
		return;
	}
	vis[k]=1;
	dfs(k+1);
	vis[k]=0;
	dfs(k+1);
}
int main(){
	maps[1][2]=maps[2][1]=1;maps[1][6]=maps[6][1]=1;	//Á¬Í¨µÄ´æÍ¼ 
	maps[6][7]=maps[7][6]=1;maps[6][5]=maps[5][6]=1;
	maps[2][7]=maps[7][2]=1;maps[2][3]=maps[3][2]=1;
	maps[5][7]=maps[7][5]=1;maps[5][4]=maps[4][5]=1;
	maps[3][7]=maps[7][3]=1;maps[4][3]=maps[3][4]=1;
	dfs(1);
	cout<<ans;
}
