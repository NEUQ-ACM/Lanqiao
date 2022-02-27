#include <bits/stdc++.h>
using namespace std;
int m[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool hui(int a)
{
	string s;
	while(a)
	{
		s += a % 10;
		a/=10;
	}
	int l = 0, r = 7;
	while(l <= r)
	{
		if(s[l++] != s[r--]) return 0;
	}
	return 1;
}
bool ABAB(int a)
{
	if(!hui(a)) return 0;
	if((a%10000/1000 == a%100/10) && (a%1000/100 == a%10) && (a%100/10 != a%10)) return 1;
	else return 0;
}
int main()
{
	int n;	
	int ans1 = 0, ans2 = 0;
	cin >> n;
	for (int i = n+1; i <= 99991231; i++)
	{
		int day = i %100;
		int month = ((i-day)%10000)/100;
		int year = (i - day - (month * 100))/10000;
		
		if(month > 12) continue;
		if(m[month] < day) continue; 
		
		if(!ans1)
		{
			if(hui(i)) ans1 = i;
		}
		
		if(!ans2)
		{
			if(ABAB(i)) ans2 = i;
		}
		if(ans1 && ans2) break;
	}
	cout << ans1 << endl << ans2 << endl;
	return 0;
}
