#include<bits/stdc++.h>
using namespace std;
int main(){
	long long f[100001],n,sum=0;
	int m=0;
	n=2021041820210418;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			m++;
			f[m]=i;
			if(i!=n/2){
				m++;
				f[m]=n/i;
			}
		}
	}
	sort(f+1,f+m+1);
	for(int i=1;i<=m;i++){
		for(int j=i;j<=m;j++){
			for(int k=j;k<=m;k++){
				if(f[i]*f[j]*f[k]==n){
					if(f[i]==f[j]&&f[j]==f[k])	sum+=1;
					else if(f[i]==f[j]||f[j]==f[k]||f[i]==f[k])	sum+=3;
					else	sum+=6;
				}
				else if(f[i]*f[j]*f[k]>n)	break;
			}
		}
	}
	cout<<sum;
	return 0;
}
