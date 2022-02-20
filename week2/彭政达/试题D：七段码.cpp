#include <bits/stdc++.h>
using namespace std;
int use[11],ans,edge[11][11],fa[11];
int find(int u){
	if(fa[u]==u) return u;
	fa[u]=find(fa[u]);
	return fa[u];
}
void dfs(int d){
	if(d>7){
		for(int i=1;i<=7;i++) fa[i]=i;
		for(int i=1;i<=7;i++)
			for(int j=1;j<=7;j++)
				if(edge[i][j] && use[i] && use[j]){
					int fx=find(i),fy=find(j);
					if(fx!=fy) fa[fx]=fy;
				}
		int k=0;
		for(int i=1;i<=7;i++)
			if(use[i] && fa[i]==i) k++;
		if(k==1) ans++;
		return;
	}
	use[d]=1;dfs(d+1);
	use[d]=0;dfs(d+1);
}
int main(){
	edge[1][2]=edge[1][6]=1;
	edge[2][1]=edge[2][7]=edge[2][3]=1;
	edge[3][2]=edge[3][4]=edge[3][7]=1;
	edge[4][3]=edge[4][5]=1;
	edge[5][4]=edge[5][6]=edge[5][7]=1;
	edge[6][1]=edge[6][5]=edge[6][7]=1;
	dfs(1);
	cout<<ans<<endl;
}
