
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=1,all=0;
    while(n<=2020){   
        int x=n;
        while(x){
            int r=x%10;
            if(r==2) all++;
            x=x/10;
        }
        n++;
    }
    cout<<all<<endl;
    return 0;
}
