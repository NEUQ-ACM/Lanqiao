/*用dfs用的多，都快把bfs忘掉了*/
#include<bits/stdc++.h>
using namespace std;
char g[105][105];
bool vis[105][105];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,ax,ay;  
struct Node{
    int x,y,step;
};

void bfs(){
    queue<Node> q;
    memset(vis,0,sizeof(vis));
    Node head,tmp;
    head = {ax,ay,0};
    q.push(head);
    vis[ax][ay] = 1;
    while(!q.empty()){
        head = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            tmp.x = head.x+dir[i][0];
			tmp.y = head.y+dir[i][1];
			tmp.step = head.step+1;
            if(tmp.x<1||tmp.x>n||tmp.y<1||tmp.y>n) continue;
			if(vis[tmp.x][tmp.y]) continue;
			if(g[tmp.x][tmp.y]==g[head.x][head.y]) continue;
            if(g[tmp.x][tmp.y]=='B'){
                cout<<tmp.step<<endl;
                return;
            }
            vis[tmp.x][tmp.y] = 1;
            q.push(tmp);
        }
    }
    cout<<-1<<endl;
    return;
}

int main(){
    while(cin>>n){
        for(int i=1; i<=n; i++) 
            for(int j=1; j<=n; j++) {
                cin>>g[i][j];
                if(g[i][j]=='A') ax=i,ay=j;
            }
        bfs();
    }
    return 0;
}
