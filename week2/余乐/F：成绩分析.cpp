#include <cstdio>
using namespace std;
int n, minn = 100, maxn, tot;
int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		int a;
		scanf("%d", &a);
		if(a > maxn) maxn = a;
		if(a < minn) minn = a;
		tot += a;
	}
	double ave = (double) tot / n;
	printf("%d\n%d\n%.2lf", maxn, minn, ave);
	return 0;
} 
