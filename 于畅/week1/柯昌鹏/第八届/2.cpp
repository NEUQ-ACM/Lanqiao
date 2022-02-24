#include <iostream>
using namespace std;

const int maxn = 10000000;
int prime[maxn];
bool is_prime[maxn + 10]; // is_prime[i]为true表示i是素数

bool is_Prime(int n)
{
    int i = 0;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return n != 1;
}

//返回n以内的素数
int sieve(int n)
{
    int p = 0;
    //初始化
    for (int i = 0; i <= n; i++)
    {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;

    for (int i = 0; i <= n; i++)
    {
        if (is_prime[i])
        {
            prime[p++] = i; //将素数添加到prime中
            // 1.首先2是素数, 然后划去所有2的倍数
            // 2.表中剩余的最小数字是3, 他不能被更小的数整除,所以是素数
            //再将表中所有3的倍数都划去
            // 3.以此类推, 如果表中剩余的最小数字是m时,m就是素数。然后将表中所有m的倍数都划去
            for (int j = 2 * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return p;
}

void solve()
{
    int N = 10000;
    int cnt = sieve(N);

    //公差
    for (int d = 10; d < N; d++)
    {
        //枚举N以内所有素数
        for (int i = 0; i < cnt; i++)
        {
            int tmp = prime[i],
                flag = true;
            //是否连续10个都为素数
            for (int j = 0; j < 9; j++)
            {
                if (tmp + d > N || !is_Prime(tmp + d))
                {
                    flag = false;
                    break;
                }
                else
                {
                    tmp += d; //下一个素数
                }
            }
            if (flag)
            {
                cout << d << " " << prime[i] << endl;
                return;
            }
        }
    }
}

int main()
{
    solve();
    return 0;
}