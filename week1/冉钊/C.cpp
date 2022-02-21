#include<bits/stdc++.h>
using namespace std;
long long ans;
const long long que=2021041820210418;
vector<long long>ys;
int main(){
    ys.push_back(1);
    ys.push_back(que);
    for(int i=2;i<=sqrt(que);i++){
        if(que%i==0){
            ys.push_back(i);
            ys.push_back(que/i);
        }
    }
    for(int i=0;i<ys.size();i++){
        for(int j=0;j<ys.size();j++){
            for(int k=0;k<ys.size();k++){
                if(ys[i]*ys[j]*ys[k]==que)ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}