#include<bits/stdc++.h>
using namespace std;
int a[50][50];
int main(){
	/*
	这里分奇数偶数情况讨论 	
	
	*/ 
	int id=0;//要填的数 
	for(int i=1;i<=40;i++){
		for(int j=0;j<i;j++)  //斜着填
		{
		  if(i&1){   //奇数
		  a[i-j][j+1]=++id;	  
		} 
		  else{
		  a[j+1][i-j]=++id;	
		} 
	}
}
	      cout<<a[20][20]<<endl; 
	return 0;
} 

