#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
int mmap[2100][2100];
void floyed(){
    for(int i=1;i<=2021;i++){
        for(int j=1;j<=2021;j++){
            for(int k=1;k<=2021;k++){
                if(mmap[i][j]>mmap[i][k]+mmap[k][j]){
                    mmap[i][j]=mmap[i][k]+mmap[k][j];
                }
            }
        }
    }
}
void dijs(){
    
}
int gongbei(int i,int j){
    if(i == j)return i;
    else if(i > j){
        for(int k = 1;;k++){
            if(i * k % j==0)return i*k;
        }
    }
    else {
        for(int k = 1;;k++){
            if(j * k % i==0)return j*k;
        }
    }
}

int main(){
    for(int i=1;i<=2021;i++){
        for(int j=i+1;j<=2021;j++){
            if(fabs(i-j)>21){
                mmap[i][j]=INF;
                mmap[j][i]=INF;
            }else{
                mmap[j][i]=mmap[i][j]=gongbei(i,j);
            }
        }
    }
    floyed();
    cout<<mmap[1][2021];
    return 0;
}
// int gcd(int x, int y)
// {
//     if (y == 0)
//         return x;
//     else
//         return gcd(y, x % y);
// }
// int lcm(int x, int y)
// {
//     return x / gcd(x, y) * y;
// }