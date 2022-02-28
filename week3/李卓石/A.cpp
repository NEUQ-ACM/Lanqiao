#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(int x)
{
	while (x) {
        int t = x % 10;
        if (t == 2 || t == 0 || t == 1 || t == 9) 
        	return 1;
        x /= 10;
    }
	return 0;
}

int main()
{
	ll s=0;
	for(int i=1;i<=2019;i++)
	{
		if(check(i))s+=i*i;
	}
	cout<<s;
	return 0;
}
