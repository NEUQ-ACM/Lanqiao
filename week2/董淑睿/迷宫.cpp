#include <bits/stdc++.h>
using namespace std;
int m, n;
struct node {
    int x,y;
    string path;
};
char maze[200][200];
bool visit[200][200];
int fx[4] = {1, 0, 0, -1};
int fy[4] = {0, -1, 1, 0};
char f[4] = {'D', 'L', 'R', 'U'};
bool judge(int x, int y, int Sx, int Sy) {
    if (x == n && y == m) return 1;
    else return 0;
}
void bfs(int Sx, int Sy) {
    queue<node> q;
    visit[Sx][Sy] = 1;
    node p;
    p.x = Sx, p.y = Sy;
    q.push(p);
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        string way = q.front().path;
        q.pop();
        if (judge(x, y, Sx, Sy)) {
            cout << way;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int Tx = x + fx[i];
            int Ty = y + fy[i];
            string Tway = way + f[i];
            if (maze[Tx][Ty] == '0' && visit[Tx][Ty] == 0 && Tx <= n && Tx > 0 && Ty <= m && Ty > 0) {
                visit[Tx][Ty] = 1;
                node T;
                T.x = Tx, T.y = Ty, T.path = Tway;
                q.push(T);
            }
        }
    }
}
int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        string T;
        cin >> T;
        for (int j = 1; j <= m; j++)
            maze[i][j] = T[j - 1];
    }
    bfs(1, 1);
    return 0;
}
