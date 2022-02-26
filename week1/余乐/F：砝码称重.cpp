#include <cstdio>
using namespace std;

int n, a[101], f[101][200001], tot, ans, u[100001];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++){
		scanf("%d", &a[i]);
		tot += a[i];
	}
	f[0][tot] = 1;
	for(int i = 1;i <= n;i ++)
		for(int j = -tot;j <= tot;j ++){
			int x = j + tot;
			if(f[i - 1][x] || f[i - 1][x - a[i]] || f[i - 1][x + a[i]])
				f[i][x] = 1;
			if(j > 0 && f[i][x]) u[j] = 1;
		}
	for(int i = 1;i <= tot;i ++)
		if(u[i]){
//			printf("%d\n", i);
			ans ++;
		}
	printf("%d", ans);
	return 0;
}
