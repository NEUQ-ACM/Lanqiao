#include <iostream>
#include <iomanip>
using namespace std;

int num[50] = { 0 };

void add(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x & 1) {
            num[cnt]++;
        }
        cnt++;
        x >>= 1;
    }
}
int main() {
    int T, n, a, b;
    cin >> T;
    while (T--) {
        int xorSum = 0, temp;
        memset(num, 0, sizeof(num));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            add(temp);
            xorSum ^= temp;
        }

        if (xorSum == 0) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0, pos = 0;
        for (int i = 30; i >= 0; i--) {
            if (num[i] & 1) {
                pos = i;
                break;
            }
        }

        if (n & 1 || num[pos] == 1) {
            cout << 1 << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}
