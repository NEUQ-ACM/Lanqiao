#include <bits/stdc++.h>
using namespace std;
int main(){
	int f[21];
	f[0]=0;
	f[1]=1;
	for(int i=1;i<20;i++){
		f[i+1]=f[i]+4*i;
	}
	cout<<f[20]<<endl;
}

