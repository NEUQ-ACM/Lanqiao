#include<bits/stdc++.h>
using namespace std;
int num[108];
set<int>s;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>num[i];
    s.insert(num[0]);
    for(int i=1;i<=n;i++)
    {
        set<int>temp(s);
        for(set<int>::iterator it=temp.begin();it!=temp.end();it++)
        {
            s.insert(abs(*it+num[i]));
            s.insert(abs(*it-num[i]));
        }
        s.insert(num[i]);
    }
    if(s.find(0)!=s.end()) cout<<s.size()-1;
    else cout<<s.size();
    return 0;
}