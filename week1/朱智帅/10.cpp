#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int M = 51, N = 101;

int n, m, w[N], f[M][N][N], st[N], ans = 0x7fffffff;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &w[i]);
        w[i] += w[i - 1];
    }
    for(int minw = 1; minw <= 2 * w[n] / m; minw++){
        memset(f, 0x7f, sizeof(f));
        f[0][0][0] = minw;
        for(int i = 1; i <= m; i++) {
            for(int j = 0; j <= n; j++){
                *st = 0;
                int p = 0, pst = 1;
                for(int k = j; k <= n; k++){
                    if(j > 0) f[i][j][k] = f[i][j - 1][k];
                    while(w[k] - w[p] >= minw){
                        if(p >= j){
                            while(*st && f[i - 1][j][p] <= f[i - 1][j][st[*st]])
                                (*st)--;
                            st[++*st] = p;
                        }
                        p++;
                    }
                    if(*st){
                        pst = min(pst, *st);
                        while(pst < *st && f[i - 1][j][st[pst + 1]] < w[k] - w[st[pst + 1]])
                            pst++;
                        while(pst > 1 && f[i - 1][j][st[pst]] > w[k] - w[st[pst]])
                            pst--;
                        f[i][j][k] = min(f[i][j][k], max(f[i - 1][j][st[pst]], w[k] - w[st[pst]]));
                        if(pst < *st)
                            f[i][j][k] = min(f[i][j][k], max(f[i - 1][j][st[pst + 1]], w[k] - w[st[pst + 1]]));
                    }
                    int pp = min(p - 1, j);
                    if(pp >= 0)
                        f[i][j][k] = min(f[i][j][k], max(f[i - 1][pp][j], w[k] - w[pp]));
                }
            }
        }
        ans = min(ans, f[m][n][n] - minw);
    }
    printf("%d", ans);
    return 0;
}