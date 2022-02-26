#include <cstdio>
#define N 10000001 
#define ll long long
using namespace std;
ll x = 2021041820210418;
int pd[N];
int a[N], t, q[N], p;
int main(){
	for(int i = 2;i <= N;i ++){
		if(pd[i] == 0) a[++ t] = i;
		for(int j = 1;j <= t;j ++){
			int x = a[j];
			if(i * x > N) break; 
			pd[i * x] = 1;
			if(i % x == 0) break;
		}
	}
	while(1){
		if(x == 1) break;
		for(int i = 1;i <= t;i ++)
			if(x % a[i] == 0){
				x /= a[i];
				q[++ p] = a[i];
				break;
			}
	}
	for(int i = 1;i <= p;i ++)
		printf("%d\n", q[i]);
	return 0;
} 
