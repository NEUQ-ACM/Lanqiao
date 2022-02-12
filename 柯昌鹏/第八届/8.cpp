#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("test01.txt");
    double value, discount;
    int ans = 0;
    double tmp = 0;
    while (in >> value >> discount)
    {
        tmp += value * discount;
        if (ans < tmp)
        {
            while (ans < tmp)
            {
                ans += 100;
            }
        }
    }
    cout << ans << endl;

    return 0;
}