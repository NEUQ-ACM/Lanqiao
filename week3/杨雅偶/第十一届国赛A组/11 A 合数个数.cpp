#include<bits/stdc++.h>
using namespace std;
int main(){
	int f[30],ans=0;
	f[1]=2;f[2]=3;f[3]=5;f[4]=7;f[5]=11;
	f[6]=13;f[7]=17;f[8]=19;f[9]=23;f[10]=29;
	f[11]=31;f[12]=37;f[13]=41;f[14]=43;
	for(int i=4;i<=2020;i++){
		for(int j=1;j<=14;j++){
			if(i%f[j]==0&&i!=f[j]){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
