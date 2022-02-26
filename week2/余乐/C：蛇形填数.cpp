#include <cstdio>
using namespace std;
int ans;
int main(){
	int n = 2 * 20 - 2;
	for(int i = 1;i <= n;i ++)
		ans += i;
	ans += 20;
	printf("%d", ans);
	return 0;
} 
