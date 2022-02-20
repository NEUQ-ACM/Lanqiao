#include <bits/stdc++.h>
using namespace std;
int a[11];
void f(int x){
	if(x<10) a[x]++;
	else{
		f(x/10);
		a[x%10]++;
	}
}
int main(){
	for(int i=0;i<2021;i++) f(i);
	cout<<a[2]<<endl;
} 
