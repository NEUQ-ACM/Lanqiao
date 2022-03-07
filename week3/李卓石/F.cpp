#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    long long n, maxnum = -3500000000ll, maxlayer, cnt = 0, flag = 0;
    cin >> n;
    for(int layer = 0; ; layer++) { 
        long long sum = 0, a;
        for(int i = 0; i < (1 << layer); i++) { // 每一层的结点个数
            cin >> a;
            sum += a;
            if(++cnt >= n) {
                flag = 1;
                break;
            }
        }
        if(sum > maxnum)
            maxnum = sum, maxlayer = layer + 1;
        if(flag) break;
    }
    cout << maxlayer;
    return 0;
}
