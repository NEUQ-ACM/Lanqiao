#include<bits/stdc++.h>
using namespace std;
int main()
{
    set <int> p;
    vector<int> t;
    int n;
    cin>>n;
    int f[n];
    for (int i = 0; i < n; i++)
    {
        cin>>f[i];
    }
    p.insert(f[0]);
    for(int i = 1; i < n; i++)
    {
        for(auto it : p)
        {
            t.push_back(it+f[i]);
            t.push_back(abs(it-f[i]));
        }
        p.insert(f[i]);
        for(auto it : t)
        {
            p.insert(it);
        }
        t.clear();
    }
    // for(auto it: p)cout<<it<<" ";
    cout<<p.size();
    // system("pause");
    return 0;
}