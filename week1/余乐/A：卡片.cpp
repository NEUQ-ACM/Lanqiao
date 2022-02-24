#include <cstdio>
using namespace std;
int num[10];
int main(){
	for(int i = 0;i < 10;i ++)
		num[i] = 2021;
	for(int i = 1;;i ++){
		int x = i, flag = 1;
		while(x){
			int p = x % 10;
			num[p] --;
			if(num[p] == -1){
				printf("%d", i - 1);
				flag = 0;
				break;
			}
			x /= 10;
		}
		if(flag == 0) break;
	}
	return 0;
} 
