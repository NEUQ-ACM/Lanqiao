#include <cstdio>
using namespace std;
long long ans;
int pd(int x){
	while(x){
		int p = x % 10;
		if(p == 2 || p == 0 || p == 1 || p == 9) return 1;
		x /= 10;
	}
	return 0;
}
int main(){
	for(int i = 1;i <= 2019;i ++)
		if(pd(i))
			ans += i * i;
	printf("%lld", ans);
	return 0;
}
