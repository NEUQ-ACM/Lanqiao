#include<bits/stdc++.h>
using namespace std;
long long ans,ans2;
bool check(int i){
    if(i==0)return 0;
    else if(i%10==2||i%10==0||i%10==1||i%10==9){
        return 1;
    }
    else
	return check(i/10);
}
int main(){
    for(int i=1;i<=2019;i++){
        if(check(i))ans+=i*i;
    }
    cout<<ans<<endl;
    return 0;
}