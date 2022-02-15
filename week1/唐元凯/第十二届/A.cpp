#include<vector>
#include<iostream>
using namespace std;

int main() {
    vector<int>num(10, 2021);
    bool sign = 1;
    int cur = 0,inp;
    while (sign) {
        ++cur;
        inp = cur;
        do
        {
            --num[inp % 10];
            if (num[inp % 10] < 0)sign = 0;
            inp /= 10;
        } while (inp!=0);
    }
    cout << cur-1;
}


