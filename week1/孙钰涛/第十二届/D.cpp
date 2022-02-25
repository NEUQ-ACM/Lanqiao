#include<bits/stdc++.h>
using namespace std;
int m[2030][2030];



int main()
{
    memset(m,0x3f,sizeof(m));
    for(int i=1;i<=2021;i++)
        for(int j=i+1;j<=2021;j++)
        {
            if(j-i>21) continue;
            m[i][j]=m[j][i]=i*j/__gcd(i,j);
        }
    for(int i=1;i<=2021;i++)
        for(int j=1;j<=2021;j++)
            for(int k=1;k<=2021;k++)
                if(m[i][k]>m[i][j]+m[j][k]) m[i][k]=m[i][j]+m[j][k];
    cout<<m[1][2021];
    return 0;
}
//10266837