#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int move1[5] = {-1, 0, 1, 0};
int move2[5] = {0, -1, 0, 1};
void dfs(char s[1005][1005], int maxlo, int maxhi, int lo, int hi) {
    s[lo][hi] = '.';
    for (int i = 0; i < 4; i++) {
        int newlo = lo + move1[i];
        int newhi = hi + move2[i];
        if (s[newlo][newhi] == '#' && newlo >= maxlo && newlo <= maxhi &&
            newhi >= maxlo && newhi <= maxhi)
            dfs(s, maxlo, maxhi, newlo, newhi);
    }
}
int dfs_num(char s[1005][1005], int lo, int hi)  
{
    int num = 0;
    for (int i = lo; i <= hi; i++)
        for (int j = lo; j <= hi; j++) {
            if (s[i][j] == '#') {
                dfs(s, lo, hi, i, j);
                num++;
            }
        }
    return num;
}
int main() {
    char s[1005][1005], s1[1005][1005];
    int n;
    cin >> n;
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> s[i][j];
            s1[i][j] = s[i][j];
        }
    for (int i = 1; i <= n; i++)  
        for (int j = 1; j <= n; j++) {
            if (s[i - 1][j] == '.' || s[i][j - 1] == '.' ||
                s[i + 1][j] == '.' || s[i][j + 1] == '.')
                s1[i][j] = '.';
        }
    int sum1 = dfs_num(s, 1, n);   
    int sum2 = dfs_num(s1, 1, n);  
    cout << sum1 - sum2 << "\n";
    return 0;
}

