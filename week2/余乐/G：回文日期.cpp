#include <cstdio>
using namespace std;
int a, q[11];
int main(){
	scanf("%d", &a);
	int x = a / 10000;
	while(1){
		x ++;
		int n = x, m, d, pd = 1, r = 1;
		if(x % 100 == 0){
			if(x % 400) r = 0;
		}
		else if(x % 4) r = 0;
		for(int i = 1;i <= 4;i ++){
			q[i] = n % 10;
			n /= 10;
		}
		m = q[1] * 10 + q[2];
		if(m > 12 || m < 1) pd = 0;
		d = q[3] * 10 + q[4];
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
			if(d > 31) pd = 0;
		}
		else if(m == 4 || m == 6 || m == 9 || m == 11){
			if(d > 30) pd = 0;
		}
		else if(d > 28 + r) pd = 0;
		if(pd) break;
	}
	int ans = q[4];
	for(int i = 3;i >= 1;i --){
		ans *= 10;
		ans += q[i];
	}
	printf("%d",ans);
	for(int i = 1;i <= 4;i ++)
		printf("%d", q[i]);
	printf("\n");
	x = a / 10000;
	while(1){
		x ++;
		int n = x, m, d, pd = 1, r = 1;
		if(x % 100 == 0){
			if(x % 400) r = 0;
		}
		else if(x % 4) r = 0;
		for(int i = 1;i <= 4;i ++){
			q[i] = n % 10;
			n /= 10;
		}
		if(q[1] != q[3]) pd = 0;
		if(q[2] != q[4]) pd = 0;
		m = q[1] * 10 + q[2];
		if(m > 12 || m < 1) pd = 0;
		d = q[3] * 10 + q[4];
		if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
			if(d > 31) pd = 0;
		}
		else if(m == 4 || m == 6 || m == 9 || m == 11){
			if(d > 30) pd = 0;
		}
		else if(d > 28 + r) pd = 0;
		if(pd) break;
	}
	int ans2 = q[4];
	for(int i = 3;i >= 1;i --){
		ans2 *= 10;
		ans2 += q[i];
	}
	printf("%d",ans2);
	for(int i = 1;i <= 4;i ++)
		printf("%d", q[i]);
	printf("\n");
	return 0;
} 
