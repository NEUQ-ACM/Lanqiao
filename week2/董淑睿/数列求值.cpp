#include <bits/stdc++.h>
using namespace std;
int a[20190330];
int main() {
    a[1]=1,a[2]=1,a[3]=1;
    for (int i = 4; i <= 20190324; i++)
        a[i] = (a[i - 1] + a[i - 2] + a[i - 3])%10000;
    cout<<a[20190324];
    return 0;
}