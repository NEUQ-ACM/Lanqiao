#include<bits/stdc++.h>
using namespace std;
long long n=123456789765444;
long long num[200000005];
int main(){
    int count=0;
    for(long long i=1;i*i<=n;i++){
    	if(n%i==0){
    		num[count++]=i;
    		num[count++]=n/i;
		}
	}
	long long ans=0;
	for(int i=0;i<count;i++){
		for(int j=0;j<count;j++){
			for(int k=0;k<count;k++){
			if(num[i]*num[j]*num[k]==n)ans++;	
			}
		}
	}
	cout<<ans;
	return 0;
}
