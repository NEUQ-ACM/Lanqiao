#include<bits/stdc++.h>
using namespace std;
int main(){
	long long sum=0;
	int flag=0;
	for(int i=1;i<=2019;i++){
		int j=i;
		while(j){
			if(j%10==2||j%10==0||j%10==1||j%10==9){
				flag=1;
				break;
			}
			j/=10;
		}
		if(flag) sum+=i*i;
		flag=0;
	}
	cout<<sum<<endl;
}
