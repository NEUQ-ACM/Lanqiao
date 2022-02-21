#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b=0;
	for(int i=1;i<=2020;i++){
		a=i;
		while(a!=0){
			if(a%10==2)	b++;
			a=a/10;
		}
	}
	cout<<b;
	return 0;
} 
