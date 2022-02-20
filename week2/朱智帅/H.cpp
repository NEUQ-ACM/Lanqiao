#include<iostream>
using namespace std;
int main()
{
	string S;
	cin >> S;
	long long n = S.size(), i, j, k, nowpos[26] = { 0 }, lastpos[100001] = { 0 }, sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum = sum + (nowpos[S[i - 1] - 'a'] - lastpos[nowpos[S[i - 1] - 'a']]) * (i - nowpos[S[i - 1] - 'a']);
		lastpos[i] = nowpos[S[i - 1] - 'a'];
		nowpos[S[i - 1] - 'a'] = i;
	}
	for (i = 0; i < 26; i++)
	{
		sum = sum + (nowpos[i] - lastpos[nowpos[i]]) * (n + 1 - nowpos[i]);
	}
	cout << sum << endl;
}