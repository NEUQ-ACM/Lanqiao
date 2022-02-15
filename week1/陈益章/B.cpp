#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x;
    double y;
}p;
set<pair<double,double>>s;
vector<point>v;
int main()
{
    for(int i=0;i<20;i++)
        for(int j=0;j<21;j++)
        {
            p.x=i;
            p.y=j;
            v.push_back(p);
        }
    for(int i=0;i<v.size();i++)
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i].x==v[j].x||v[i].y==v[j].y)continue;
            double k,b;
            k=(v[j].y-v[i].y)/(v[j].x-v[i].x);
            b=(v[i].x*v[j].y-v[j].x*v[i].y)/(v[i].x-v[j].x);
            pair<double,double>temp;
            temp.first=k;
            temp.second=b;
            s.insert(temp);
        }
    cout<<s.size()+41;
    return 0;
}
