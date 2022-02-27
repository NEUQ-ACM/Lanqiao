#include <iostream>
using namespace std;
const int N = 21;
const int M = 1 << N; // 2^21;
long long num[M][N];//状态，起点,保存方法的数量
bool sign[N][N];
int gcd(int a, int b) //最大公约数
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    for (int i = 1; i <= 21; i++)
        for (int j = 1; j <= 21; j++)
            if (gcd(i, j) == 1)         //如果互质
                sign[i - 1][j - 1] = true; //有通道
    num[1][0] = 1;
    for (int i = 1; i <= M - 1; i++)//遍历状态
        for (int j = 0; j <= 20; j++)//遍历起点
            if (i >> j & 1) //如果i的第j位为1。这个状态走过这个点
                for (int k = 0; k <= 20; k++)
                    if (i - (1 << j) >> k & 1 && sign[k][j]) //如果 使i的第j位为0而第k位为1，k和j导通。这个状态是由k走到j得来的。
                        num[i][j] += num[i - (1 << j)][k];//于是+=由k出发到这个状态的数量
    long long ans = 0;
    for (int i = 1; i <= 20; i++)//对所有节点都走过的状态，遍历不同的起点
        ans += num[M - 1][i];
    cout << ans ;
}
