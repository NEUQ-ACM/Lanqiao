#include<bits/stdc++.h>
using namespace std;
long long ys[1000000],n=2021041820210418,cnt=0;
int num=0;
int main(){
    
    for(long long i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ys[++cnt]=i;
            if(i!=sqrt(n))
            ys[++cnt]=n/i;
        }
    }
     for(int i=1;i<=cnt;i++){
        for(int j=1;j<=cnt;j++){
            if(n%(ys[i]*ys[j])==0)
                num++;
        }
    }
    cout<<num;
    }

