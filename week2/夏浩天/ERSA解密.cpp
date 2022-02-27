//确实不太会......慢慢消化吧......（悲）
//来源：https://blog.csdn.net/weixin_43107805/article/details/89525061
#include<iostream>
using namespace std;
const int N = 500000;
long long n = 1001733993063167141;
long long p = 891234941;
long long q = 1123984201;
long long c = 20190324; //密文 
long long d = 212353;   //公钥
long long m = (p - 1) * (q - 1); //求 X = c^e mod (p-1)*(q-1); 
long long e; // d*e≡1(mod Φ(n))     
long long ex_gcd(long long a, long long b, long long& x, long long& y)//扩展欧几里得 
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int r = ex_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return r;
}
long long mod_reverse(long long a, long long n)//ax=1(mod n) 求a的逆元x d*e=1mod(m)
{
	long long d, x, y;
	d = ex_gcd(a, n, x, y);
	if (d == 1)
		return (x % n + n) % n;
	else
		return -1;
}
//快速乘 
long long mult_mod(long long a, long long b, long long m) // 计算 a*b mod m
{
	long long res = 0;
	while (b) 
	{
		if (b & 1) res = (res + a) % m; 
		a = (a * 2) % m;
		b >>= 1;// == 'b*=2'
	}
	return res;
}
//快速幂      
long long quick_mod(long long a, long long b, long long m)
{
	long long ans = 1;
	a = a % m;
	while (b != 0)
	{
		if (b & 1) ans = mult_mod(ans, a, m) % m;//(ans*a)%m;             
		a = mult_mod(a, a, m) % m;  //a=(a*a)%m; 

		b >>= 1;
	}
	return ans;

}
int main()
{
	cout << "m=" << m << endl;
	e = mod_reverse(d, m);
	cout << "e=" << e << endl;
	cout << "d=" << d << endl;

	long long x = quick_mod(c, e, m);
	cout << x << endl; //明文 
	cout << quick_mod(x, d, m) << endl;
}