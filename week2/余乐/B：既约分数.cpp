#include <cstdio>
using namespace std;

int ans;
int gcd(int i, int j){
	while(i){
		if(i < j){
			int c = i;
			i = j;
			j = c;
		}
		i -= j;
	}
	if(j == 1) return 1;
	return 0;
}

int main(){
	for(int i = 1;i <= 2020;i ++)
		for(int j = 1;j <= 2020;j ++)
				if(gcd(i, j))
					ans ++;
	printf("%d", ans);
	return 0;
} 
