#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	for(int i=1;i<10001;i++){
		int m=i;
		while(m){
			int len=m%10;
			m/=10;
			a[len]++;
			if(a[len]>2021){
				if(!m) cout<<i<<endl;
				else cout<<i-1<<endl;
				return 0;
			}
		}
	}
}
