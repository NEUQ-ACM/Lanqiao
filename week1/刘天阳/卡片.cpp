#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	int ans = 1;
	for (int i = 1;;i++)
	{
		int t = i;
		while(t)
		{
			int k = t%10;
			a[k]++;
			if(a[k] == 2021) 
			{
				cout << i;
				return 0;
			}
			t/=10;
			
		}
	}
	return 0;
}
