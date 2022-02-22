#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,f[20],m,n,flag;
	f[0]=f[1]=f[2]=f[3]=f[4]=f[5]=f[6]=f[7]=f[8]=f[9]=0;
	i=1;
	flag=0;
	while(1){
		n=i;
		while(n>0){
			m=n%10;
			f[m]+=1;
			if(f[m]==2022){
				flag=1;
				break;
			}
			n=n/10;
		}
		if(flag==1){
			cout<<i-1;
			break;
		}
    i=i+1;
	}
	return 0;
}
