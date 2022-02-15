#include<bits/stdc++.h>
using namespace std;
int a[10];
int flag=0;
int main(){
	for(int i=1;i<=10000;i++){
		if(flag==1) break;
		int j=i;
		while(j){
			int len=j%10;
			a[len]++;
			if(a[len]>2021){
				flag=1;
				if(j==0)
				cout<<i<<endl;
				else cout<<i-1<<endl;
				break;
			}
			j/=10;
		}
	}
}
