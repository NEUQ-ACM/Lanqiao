#include<bits/stdc++.h>
using namespace std;

int gcd(int i,int j){          
    if(i%j==0) return j;
    else return gcd(j,i%j);
}

int main(){
    int sum=0;
    for(int i=1;i<=2020;i++)
        for(int j=1;j<=2020;j++){
            if(gcd(i,j)==1) sum++;
        }
    cout<<sum<<endl;
    return 0;
}


