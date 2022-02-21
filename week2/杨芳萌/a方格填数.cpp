/* 用一个不动脑子的方法： 
首先生成一个 1 到 10 的全排列（ 10！= 3628800 ） 
然后对于每一个全排列判断一下是否符合题意 
最后答案是42 */
#include<bits/stdc++.h>
using namespace std;
int a[10] = {1,2,3,4,5,6,7,8,9,10};
int k = 3628800, cnt=0;
int main(){
	while(k--) {
		next_permutation(a,a+10);
		bool flag = 0;
		for(int i=0; i<=3; i++) //第一行左右判断 
			if(a[i]>a[i+1]) { flag=1; break; }
		if(flag==1) continue;
		
		for(int i=5; i<=8; i++) //第二行左右判断 
			if(a[i]>a[i+1]) { flag=1; break; }
		if(flag==1) continue;
		
		for(int i=0; i<=4; i++) //上下判断 
			if(a[i]>a[i+5]) { flag=1; break; } 
		if(flag==1) continue;
		
		cnt++;		
	}	
	printf("%d\n",cnt);
    return 0;
}
 
