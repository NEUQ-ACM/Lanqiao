/*其实就是n=a*b*c，找出有多少对abc
先质因数分解，然后把他的质因子分配在三个位置
答案也就是分配的方案数*/
#include<bits/stdc++.h>
using namespace std;
#define int long long  
const int N = 2021041820210418;
int n,cnt,p[10000],q[10000];
void factorize(int x) {
	int end = sqrt(x);
	for(int i=2; i<=end; i++) {
		if(x%i==0) cnt++, p[cnt] = i;
		while(x%i==0) { q[cnt] ++; x /= i; }
	}
	if(x>1) p[++cnt] = x;
} 
signed main(){
	factorize(N);
	for(int i=1; i<=cnt; i++) printf("%d %d\n",p[i],q[i]); 
    return 0;
}
/*先写成这样，打出来看一下
2 2 17 131 2857 5882353   //这一行是质因子 
1 3 1  1   1    1		  //这一行是次幂
对于2 17 131 2857 5882353 都是一次的，所以是3^5种 
对于2是3次的，可以003,012,021,030,102,111,120,201,210,300,十种 
所以答案就是3^5*10 = 2430
*/ 
 
