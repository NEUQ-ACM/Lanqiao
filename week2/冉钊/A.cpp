#include<bits/stdc++.h>
using namespace std;
int count(int num){
    int ans=0;
    if(num==0)return 0;
    else{
        int temp=num%10;
        if(temp==2)ans=1+count(num/10);
        else ans=0+count(num/10);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int ans=0;
    for(int i=1;i<=2020;i++){
        ans+=count(i);
    }
    cout<<ans;
    return 0;
}