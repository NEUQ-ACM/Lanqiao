#include <iostream>
#include <set>
using namespace std;
set<int> w;
int main()
{
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n;i++)
    {
        cin >> list[i];
    }
    w.insert(list[0]);
    for (int i = 1; i < n;i++)
    {
        int cache[200],p=0;
        for (auto it = w.begin(); it != w.end();it++)
        {
                cache[p++] = abs(*it + list[i]);
                cache[p++] = abs(*it - list[i]);
        }
        for (int j = 0; j < p;j++)
        {
            w.insert(cache[j]);
        }
        w.insert(list[i]);
    }
    cout << w.size();
}
