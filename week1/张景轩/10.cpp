#include <bits/stdc++.h>
using namespace std;
const int maxn = 152;

int n, m, w[maxn], rest[maxn];

bool check(int l, int r) 
{
    while (l <= r) 
    {
        if (rest[l] == 0) 
        {
            return false;
        }
      l++;
    }  
  return true;
}

int dfs(int child, int cMax, int cMin) {
    if (child == m) {
        for (int i = 0; i < n; i++) 
        {
            if (rest[i] == 2) 
            {
                return 0x3f3f3f3f;
            }
    }
        return cMax - cMin;
    }
    int ret = 0x3f3f3f;
    for (int l = 0; l < n; l++) 
    {
        for (int r = l; r < n; r++) 
        {
            if (!check(l, r)) 
            {
                continue;
            }
            int sum = 0;
            for (int i = l; i <= r; i++) 
            {
                sum += w[i];
                rest[i]--;
            }
            int temp = dfs(child + 1, max(cMax, sum), min(cMin, sum));
            for (int i = l; i <= r; i++) 
            {
                rest[i]++;
            }
            ret = min(ret, temp);
        }
  }

  return ret;
}

int main() 
{
    cin>>n>>m;
    for (int i=0;i<n;i++) 
    {
        cin>>w[i];
        rest[i] = 2;
    }
    int ans = dfs(0, -0x3f3f3f, 0x3f3f3f);
    cout<<ans<<endl;

    return 0;
}
