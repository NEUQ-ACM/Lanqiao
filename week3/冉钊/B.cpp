#include<bits/stdc++.h>
using namespace std;
const int maxn = 20200324;
int line[maxn];
int change(int i){
    int a,b,c,d;
    d = i % 10;
    i =i / 10;
    c = i % 10;
    i = i / 10;
    b = i % 10;
    i = i / 10;
    a = i % 10;
    return a * 1000+b * 100+c * 10+d;
}
int main(){
    
    line[1] = 1;line[2] = 1;line[3] = 1;
    for(int i = 4;i <= 20190324;i++){
        line[i] = line[i-1]+line[i-2]+line[i-3];
        if(line[i] > 9999){
            line[i] = change(line[i]);
        }
    }
    cout<<line[20190324];
    return 0;
}