#include<iostream>
#include<cmath>
using namespace std;

int m,n;
int a = 0;
double st[100000],d[100000];
double eps = 1e-6;

bool check(double k,double t)
{
    for(int i=0;i<a;i++)
    {
        if(abs(st[i])-k<eps && abs(d[i]-t)<eps)
        {
            return false;
        }
        d[a] = t;
        st[a] = k;
        a++;
        return true;
    }
}

int main()
{
    cin>>n;
    m = n + 1;
    int ans = 0;
    for(int x1=0;x1<n;x1++)
    {
        for(int y1=0;y1<m;y1++)
        {
            for(int x2=0;x2<n;x2++)
            {
                for(int y2=0;y2<m;y2++)
                {
                    if(x1 == x2)
                    {
                        continue;
                    }
                    double detaX,detaY;
                    detaX = x2 - x1;
                    detaY = y2 - y1;
                    double k;
                    k = detaY/detaX;

                    if(check(k,y1-k*x1))
                    {
                        ans++;
                    }
                }
            }
        }
    }
    cout<<ans + m;
    return 0;
}