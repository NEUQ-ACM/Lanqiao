#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int n = 30, m = 50;
int delta[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
int way[n + 5][m + 5], map[n + 5][m + 5], vis[n + 5][m + 5];
char cc[5] = "DLRU";
char ans[n * m + 5];
struct node {
    int x, y;
};
int main() {
//freopen("maze.txt", "r", stdin);	
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char a = ' ';
            while(a != '1' && a != '0')cin >> a;
            map[i][j] = a == '1' ? 1 : 0;
        }
    queue<node> q;
    node tmp = {0, 0};
    q.push(tmp);
    vis[0][0] = 1;
    while(!q.empty()) {
        node now = q.front();
        q.pop();
        for(int k = 0; k < 4; k++) {
            int x = now.x + delta[k][0], y = now.y + delta[k][1];
            if(x < 0 || y < 0 || x >= n || y >= m
                    || vis[x][y] || map[x][y])
                continue;
            vis[x][y] = 1, way[x][y] = k;
            node tmp = {x, y};
            q.push(tmp);
        }
    }
    int x = n - 1, y = m - 1, num = 0;
    while(x != 0 || y != 0) {
        int k = way[x][y];
        ans[num++] = cc[k];
        x -= delta[k][0], y -= delta[k][1];
    }
    num--;
    do {
        cout << ans[num];
    } while(num--);
    return 0;
}
