#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){
	int z;
	z=x%y;
 	while(z!=0) 
 	{
  		x = y;  
  		y = z;  
  		z =x%y; 
 	}
	return y;
}
int main(){
	int a=0;
	for(int i=1;i<2020;i++){
		for(int j=i+1;j<=2020;j++){
			if(gcd(i,j)==1)	a++;
		}
	}
	cout<<a*2+1;
	return 0;
}
