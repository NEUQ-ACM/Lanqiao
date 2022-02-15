#include<bits/stdc++.h>
using namespace std;
int temp;
int maxn=2021;
int ans=1001;
int sum1=280+21;
int examm(int ans){
    int n=0;
    //  if(ans/10000==1){
    //      n++;
    //  }
    //  temp=ans%10000;
    if(ans/1000==1)n++;
    temp=ans%1000;
    if(temp/100==1)n++;
    temp=temp%100;
    if(temp/10==1)n++;
    temp=temp%10;
    if(temp==1)n++;
    
    return n;
}
int main(){
    while(sum1<=maxn){
        sum1+=examm(ans);
        ans++;
    }
    cout<<ans-2;
    return 0;
}