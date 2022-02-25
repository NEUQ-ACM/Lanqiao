#include<bits/stdc++.h>
using namespace std;
int a = 1, b, ans, sum = 0;
int main()
{
	while(a < 2021)  {
        b = a;
		while(b) {
			ans = b % 10;
			if(ans == 2)  sum++;
			b /= 10;
		}
		a++;
	}
	cout << sum;
    return 0;
}