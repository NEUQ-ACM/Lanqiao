#include<bits/stdc++.h>
using namespace std;
map<pair<double, double>, bool> has;
int ans = 0;
int main(){
    for (int x1 = 0; x1 < 20; x1++) {
        for (int y1 = 0; y1 < 21; y1++) {
            for (int x2 = 0; x2 < 20; x2++) {
                for (int y2 = 0; y2 < 21; y2++) {
                    if (x1 == x2) {
                        if (!has[make_pair(1e9, x1)]) ans++, has[make_pair(1e9, x1)] = true;
                    } else {
                        double kk = double(y1 - y2) / (x1 - x2);
                        double bb = double(y1 * x2 - x1 * y2) / (x1 - x2);
                        if (!has[make_pair(kk, bb)]) ans++, has[make_pair(kk, bb)] = true;
                    }
                }
            }
        }
    }
	cout<< ans <<endl;
}