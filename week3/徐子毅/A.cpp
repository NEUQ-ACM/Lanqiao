#include <iostream>
#include <cstring>
using namespace std;
bool has2019(int num){
    string the_num=to_string(num);
    for(int i=0;i<the_num.size();i++){
        if(the_num[i]=='0'||the_num[i]=='2'||the_num[i]=='1'||the_num[i]=='9') return true;
    }
    return false;
}
int main(){
    long long sum=0;
    for(int i=1;i<=2019;i++){
        if(has2019(i)) sum+=i*i;
    }
    cout << sum << endl;
}