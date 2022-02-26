#include <cstdio>
using namespace std;

int ans, map[11][11], u[11], vis[11], tot;

void dfs(int x){
	if(vis[x] || u[x] == 0) return;
	tot ++;
	vis[x] = 1;
	for(int i = 1;i <= 7;i ++)
		if(map[x][i]) dfs(i);
}

int main(){
	map[1][2] = map[2][1] = 1;
	map[1][6] = map[6][1] = 1;
	map[6][7] = map[7][6] = 1;
	map[2][7] = map[7][2] = 1;
	map[5][6] = map[6][5] = 1;
	map[2][3] = map[3][2] = 1;
	map[5][7] = map[7][5] = 1;
	map[3][7] = map[7][3] = 1;
	map[4][5] = map[5][4] = 1;
	map[3][4] = map[4][3] = 1;
	for(int a = 0;a <= 1;a ++)
		for(int b = 0;b <= 1;b ++)
			for(int c = 0;c <= 1;c ++)
				for(int d = 0;d <= 1;d ++)
					for(int e = 0;e <= 1;e ++)
						for(int f = 0;f <= 1;f ++)
							for(int g = 0;g <= 1;g ++){
								tot = 0;
								int pd = 1, t = 0;
								if(a) u[1] = 1, t ++;
								if(b) u[2] = 1, t ++;
								if(c) u[3] = 1, t ++;
								if(d) u[4] = 1, t ++;
								if(e) u[5] = 1, t ++;
								if(f) u[6] = 1, t ++;
								if(g) u[7] = 1, t ++;
								if(t == 0) continue;
								for(int i = 1;i <= 7;i ++)
									if(u[i]){
										dfs(i);
										if(tot == t) ans ++;
										break;
									}
								for(int i = 1;i <= 7;i ++)
									u[i] = 0, vis[i] = 0;
							}
	printf("%d", ans);
	return 0;
} 
