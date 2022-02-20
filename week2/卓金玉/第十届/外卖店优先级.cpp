#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
vector<int> a[maxn];
int main()
{
    int n, m, t;
    cin >> n >> m >> t;

    int ts, id, cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        cin >> ts >> id;
        a[id].push_back(ts);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].size())
        {
            sort(a[i].begin(), a[i].end());
            bool flag = 0;
            int temp = 0;
            for (int j = 0; j < a[i].size(); ++j)
            {

                if (j == 0)
                    temp += 2;
                else
                {
                    if (a[i][j] != a[i][j - 1])
                        temp = temp - (a[i][j] - a[i][j - 1] - 1);
                    if (temp < 0)
                    {
                        temp = 0;
                        flag = 0;
                    }
                    else if (temp <= 3)
                        flag = 0;
                    temp += 2;
                    if (temp > 5)
                        flag = 1;
                }
            }
            if (t != a[i][a[i].size() - 1])
                temp = temp - (t - a[i][a[i].size() - 1]);
            if (temp < 0)
            {
                temp = 0;
                flag = 0;
            }
            else if (temp <= 3)
                flag = 0;
            cnt += flag;
        }
    }
    cout << cnt << endl;
    return 0;
}