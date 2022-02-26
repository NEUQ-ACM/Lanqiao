#include <cstdio>
using namespace std;
int a[21000000];
int main(){
	a[1] = a[2] = a[3] = 1;
	for(int i = 4;i <= 20190324;i ++){
		a[i] = (a[i - 3] + a[i - 2] + a[i - 1]) % 10000;
	}
	printf("%d", a[20190324]);
	return 0;
}
