#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    set<int>ans;
    ans.insert(num[0]);
    for (int i = 1; i < n; i++) {
        set<int>temp(ans);
        for (auto &c:temp) {
            ans.insert(abs(c + num[i]));
            ans.insert(abs(c - num[i]));
        }
        ans.insert(num[i]);
    }
    if (ans.count(0)!=0) cout << ans.size() - 1;
    else cout << ans.size();
}
