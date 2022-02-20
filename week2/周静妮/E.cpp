#include<bits/stdc++.h>
using namespace std;
long long a[3000];
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b); 
}
int main(){
    for(int i=1;i<=21;i++)a[i]=i;
    for(int i=22;i<=2021;i++){
    	int j=21;
    	long long ans=1e9;
    	while(j){
    		ans=min(ans,a[i-j]+lcm(i,i-j));
    		j--;
		}
		a[i]=ans;
	}
	cout<<a[2021];
	return 0;
}
