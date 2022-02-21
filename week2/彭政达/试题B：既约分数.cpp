#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
int main(){
    int i,j,n=0;
    for(i=1;i<=2020;i++)
        for(j=1;j<=2020;j++)
            if(gcd(i,j)==1) n++;
	cout<<n<<endl;     
}
