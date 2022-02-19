#include<bits/stdc++.h>
using namespace std;
int a[30]; 
int main(){
	a[1]=1;
	for(int i=2;i<=20;i++){
		a[i]=a[i-1]+(i-1)*4;
	}
	cout<<a[20];
}
