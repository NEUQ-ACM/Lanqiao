#include<iostream>
using namespace std;
int a[100005];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int cs = 1;//层数
    long long maxx = a[1];
    long long en = 1;//层数
    int num = 1;//该层的节点数
    int p = 2;//下一层开头指针位置
    while(true)
    {
        cs++;
        num *= 2;
        long long sum = 0;
        for (int j = p; j <= min(p + num - 1, n); j++)
            sum += a[j];
        if (sum > maxx)
        {
            en = cs;
            maxx = sum;
        }
        p += num;
        if (p > n)
            break;
    }
    cout << en << endl;
    return 0;
}