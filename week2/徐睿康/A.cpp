#include<bits/stdc++.h>
using namespace std;
int flag=0,flagg,a[20];
void work(int x){
	while(x){
		a[x%10]-=1;
		if(a[x%10]<0)flagg=1;
		x/=10;
	}
}
int main(){
	for(int i=0;i<=9;i++)a[i]=2021;
	while(1){
		flag++;
		flagg=0;
		work(flag);
		if(flagg==1){
			cout<<flag-1;
			break;
		}
	}
	return 0;
}
