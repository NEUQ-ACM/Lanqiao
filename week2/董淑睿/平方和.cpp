#include <bits/stdc++.h>
#define ll ll
using namespace std;
ll ans1,ans2;
bool judge(int n) {
    while (n) {
        int remp = n % 10;
        if (remp==1||remp==2||remp==0||remp==9) return 1;
        n /= 10;
    }
    return 0;
}
int main() {
    for (int i = 1; i <= 2019; i++)
        if(judge(i)) ans1+=i,ans2+=i*i;
    cout<<ans2;
    return 0;
}