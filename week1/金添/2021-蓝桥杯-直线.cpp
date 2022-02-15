#include <bits/stdc++.h>
using namespace std;
// https://blog.csdn.net/qq_36306833/article/details/121872050
struct node
{
    double x;
    double y;
} point[1000000];
long long num = 0;
long long ans = 0;
map<pair<double, double>, bool> visit;
void judge(node p1, node p2)
{
    double x1 = p1.x, x2 = p2.x;
    double y1 = p1.y, y2 = p2.y;
    if (x1 == x2)
        return;
    double k = (y2 - y1) / (x2 - x1);
    double b = (x2 * y1 - y2 * x1) / (x2 - x1);
    if (!visit[{k, b}])
    {
        visit[{k, b}] = 1;
        ans++;
    }
}
int main()
{
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 21; j++)
        {
            point[++num].x = i;
            point[num].y = j;
        }
    cout << num << endl;
    for (int i = 1; i <= num; i++)
    {
        for (int j = i + 1; j <= num; j++)
        {
            judge(point[i], point[j]);
        }
    }
    cout << ans + 20;
    return 0;
}