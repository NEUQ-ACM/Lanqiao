#include<bits/stdc++.h>
using namespace std;
int a,b;
bool n[22][22];
void huzhi(int a,int b){//ª•÷  
	int p;
	for(int i=2;i<=min(a,b);i++){
		if(a%i==0&&b%i==0){
			p=0;
			break;
		}
		else{
			p=1;
			
		}
	}
	if(p){
		cout<<a<<" "<<b<<endl;
		n[a][b]=n[b][a]=1;
	}
}

int main(){
	
/**/	for(int i=1;i<=21;i++)
	for(int j=1;j<=21;j++){
		n[i][j]=0;//≥ı ºªØ 
		if(!n[i][j])
		huzhi(i,j);
	}
	
	
	return 0;
}
