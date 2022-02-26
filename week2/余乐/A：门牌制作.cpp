#include <cstdio>
using namespace std;
int ans;
int main(){
	for(int i = 1;i <= 2020;i ++){
		int x = i;
		while(x){
			int y = x % 10;
			if(y == 2) ans ++;
			x /= 10;
		}
	}
	printf("%d", ans);
	return 0;
}
