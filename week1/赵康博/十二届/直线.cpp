#include<iostream>
#include<bits/stdc++.h>

using namespace std;
 
struct Line
{
    Line(double xie_,double jie_)
    :xie(xie_),
    jie(jie_)
    {
 
    }
    double xie;
    double jie;
};
 
struct LineHash
{
    hash<double> hash_double;
    size_t operator()(const Line line) const
    {
        return hash_double((line.xie*9000+line.jie));
    }
};
 
struct LineEqual
{
    bool operator()(const Line line1,const Line line2)const
    {
        return fabs(line1.jie-line2.jie)<0.00001f&&fabs(line1.xie-line2.xie)<0.00001f;
    }
};
 
 
int main()
{
    unordered_set<Line,LineHash,LineEqual> xies;
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<21;j++)
        {
            for(int i1=0;i1<20;i1++)
            {
                for(int j1=0;j1<21;j1++)
                {
 
                    if(j-j1==0)
                    {
                        continue;
                    }
                    double xie=(double)(i-i1)/(double)(j-j1);
                    double jie= i1-(j1)*xie;
                    auto ret=xies.insert(Line(xie,jie));
                    if(!ret.second)
                    {
                        
                    }
                }
            }
            
        }
    }
    cout<<xies.size()+21<<endl;
    return 1;
}