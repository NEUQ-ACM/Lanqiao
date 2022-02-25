#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if(b==0) return a;
    else return gcd(b,a%b);
}
 int main() {
     int fz=1;
     for(int i=1;i<=20;i++) fz*=2;
     int sum = 0, fm = 1;
     for(int i=1; i<=20; ++i) {
         sum += fz / fm;
         fm *= 2;
     }
     fz = gcd(sum, fm);
     sum=sum/fz;
     fm=fm/fz;
     cout << sum << "/" << fm << endl;
     return 0;
}