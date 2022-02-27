#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int main()     // 2481215
{
    int cnt=0;
    for(int i=1;i<=2020;i++)
        for(int j=1;j<=2020;j++)
            if(gcd(i,j)==1)
                cnt++;
    printf("%d\n",cnt);
    return 0;
}

