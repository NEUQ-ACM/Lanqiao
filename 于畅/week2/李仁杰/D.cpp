#include<iostream>
#include<stdlib.h>
using namespace std;
int func(int flag[], int n1, int a[][2], int r) {
	int i, j, b, c, n = 0;
	for (i = 0; i < n1; i++) {
		if (flag[i] == 1)
			continue;
		else {
			flag[i] = 1;
			n += 1;
			for (j = i + 1; j < n1; j++) {
				b = (a[i][0] - a[j][0]);
				c = (a[i][1] - a[j][1]);
				if ((b * b + c * c) <= r * r)
					flag[j] = 1;
			}
		}
	}
	return n;
}
void findsum(int sum[], int x, int a[][2], int r) {
	int i, j, b, c;
	for (i = 0; i < x; i++) {
		sum[i] = 0;
		for (j = 0; j < x; j++) {
			if (i == j)
				continue;
			else {
				b = (a[i][0] - a[j][0]);
				c = (a[i][1] - a[j][1]);
				if ((b * b + c * c) <= r * r)
					sum[i] += 1;
			}
		}
	}
}
int bigstsum(int sum[], int x) {
	int maxr = 0;
	int i;
	for (i = 1; i < x; i++) {
		if (sum[i] > sum[maxr]) {
			maxr = i;
		}
	}
	return i;
}

int main() {
		int n, r, i, j, b, c, n1, result, x;
	int(*a)[2];
	int* sum;
	int* flag;
	cin >> n >> r;
	a = (int(*)[2])malloc(sizeof(int) * n * 2);     
	sum = (int*)malloc(sizeof(int) * n);
	flag = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) {
		cin >> a[i][0] >> a[i][1];
	}
	findsum(sum, n, a, r);
	x = bigstsum(sum, n);
	n1 = n;
	for (i = 0; i < n; i++) {
		if (i == x) {
			flag[i] = 1;
			n1--;
			continue;
		}
		else {
			flag[i] = 0;
			b = (a[i][0] - a[x][0]);
			c = (a[i][1] - a[x][1]);
			if (b * b + c * c <= r * r) { 
				flag[i] = 1;
				n1--;        
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (flag[i] = 1) {   
			for (j = i; j < n - 1; j++) {
				flag[j] = flag[j + 1];
			}
		}
	}
	result = func(flag, n1, a, r) + 1;
	cout << result;
	free(a);
	free(sum);
	free(flag);
	return 0;
}