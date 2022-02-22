#include<bits/stdc++.h>
using namespace std;

int a[100005];
int f[1000005] = {0};

int find(int p){//µÝ¹éÖ¸Ïò¸ù
//	return p == f[p]-1 ? p+1 : f[p] = find(f[p]);
	if(f[p] == 0) return p;
	f[p] = find(f[p]);
	return f[p];
}

int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(f[a[i]] == 0){
			f[a[i]] = a[i]+1;
		}
		else{
			a[i] = find(a[i]);
			f[a[i]] = a[i]+1;
		}
	}

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	return 0;
}

/*
5
2 1 1 3 4

2 1 3 4 5 
*/
