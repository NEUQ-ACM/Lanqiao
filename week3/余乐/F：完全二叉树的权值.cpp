#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, d, maxn, maxd;
int main(){
	scanf("%d", &n);
	while(n > 0){
		d ++;
		int x = pow(2, d - 1);
		int tot = 0;
		for(int i = 1;i <= min(n, x);i ++){
			int a;
			scanf("%d", &a);
			tot += a;
		}
		if(tot > maxn){
			maxn = tot;
			maxd = d;
		}
		n -= x;
	}
	printf("%d",maxd);
	return 0;
}
