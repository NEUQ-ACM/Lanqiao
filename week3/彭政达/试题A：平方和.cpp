#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int f(ll a){
	if(a==0) return 0;
	if(a%10==2 || a%10==0 || a%10==1 || a%10==9) return 1;
	else return f(a/10); 
}
int main(){
	ll s=0;
	for(ll i=1;i<2020;i++)
		if(f(i)) s+=i*i;
	cout<<s<<endl;
	return 0;
} 
