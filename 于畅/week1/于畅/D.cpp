#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

vector<vector<int> > e(2022,vector<int>(2022,INF));
vector<int> d(2022,INF);
vector<bool> v(2022,0);

int main()
{
    /*for(int i=1;i<=2021;i++){
        e[i][i]=0;
        for(int j=i+1;j<=2021;j++){
            if(abs(i-j)<=21) e[i][j]=e[j][i]=i*j/__gcd(i,j);
        }
    }

    d[1]=0;

    while(1){
        int x=0;
        for(int i=1;i<=2021;i++){
            if(!v[i]&&d[x]>d[i]) x=i;
        }
        if(!x) break;
        v[x]=1;
        for(int i=max(1,x-21);i<=min(2021,x+21);i++){
            if(!v[i]) d[i]=min(d[i],d[x]+e[x][i]);
        }
    }

    cout<<d[2021];*/
    
    cout<<10266837;

    return 0;
}
