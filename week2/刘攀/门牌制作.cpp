#include<bits/stdc++.h>
using namespace std;
int main(){
	int num=0;
	for(int i=1;i<=2020;i++){
		int j=i;
		while(j){
			if(j%10==2) num++;
			j/=10;
		}
	}
	cout<<num<<endl;
}
