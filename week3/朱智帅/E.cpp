#include<iostream>
using namespace std;
long long n = 1001733993063167141;
long long d = 212353;
long long c = 20190324;
long long p = 891234941;
long long q = 1123984201;
long long phi = (p - 1) * (q - 1);

//欧几里得算法求逆元
void Ex_gcd(long long a, long long b, long long& x, long long& y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return;
	}
	long long x1, y1;
	Ex_gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
}

//快速乘求每次的余数
long long quickmul(long long a, long long b)
{
    long long sum = 0;
    while (b)
    {
        if (b % 2 == 1)
            sum = (sum + a) % n;
        a = (a + a) % n;
        b = b / 2;
    }
    return sum;
}

//快速幂
long long quickmod(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)//末位是1；
            ans = quickmul(ans, a);//这是直接的回溯法，从最后一位起，如果，如果最后一位是1，则乘a,然后在进行乘以它本身，以为乘1之后一定为偶数，也就是b/2;
        a = quickmul(a, a);
        b = b / 2;
    }
    return ans;
}
int main()
{
	long long e, x, y;
	Ex_gcd(d, (q - 1) * (p - 1), e, y);
	e = (e + phi) % phi;

    x = quickmod(c, e);
    cout << x;
	return 0;
}