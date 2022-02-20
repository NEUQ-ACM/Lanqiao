#include <bits/stdc++.h>
using namespace std;
int a[10], res;
/**
 * 20210 2021
 * 3181
 */
bool func(int n)
{
    while (n) {
        int ss = n % 10;
        if (a[ss] == 0)
            return false;
        a[ss]--;
        n /= 10;
    }
    return true;
}
int main()
{
    for (int i = 0; i <= 9; i++) a[i] = 2021;
    while (func(res + 1)) res++;
    cout << res;
    return 0;
}