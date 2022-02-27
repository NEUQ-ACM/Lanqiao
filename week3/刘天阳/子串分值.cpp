#include <bits/stdc++.h>
using namespace std;
vector<int> pos[26];  //记录字母的位置 
int main()
{
	string s;
	cin >> s;
	int l = s.length();
	for (int i = 0; i < l; i++)
	{
		int t = s[i] - 'a';
		if(!pos[t].size()) pos[t].push_back(-1);
		pos[t].push_back(i);
	 } 
	 long long ans = 0;
	 
	for (int i = 0; i < 26; i++)
		if(pos[i].size()) pos[i].push_back(l);
	for (int i = 0; i < 26; i++)
	{
		int k = pos[i].size();
		if(k)
		{
			for (int j = 1; j < k-1; j++)
			{
				long long x = pos[i][j] - pos[i][j-1] - 1;
				long long y = pos[i][j+1] - pos[i][j] - 1;
				ans += x + y + x*y;
			}
		}
	}
	ans += l;
	cout << ans << endl;
	
	return 0;
}
/*链接：https://www.acwing.com/solution/content/41386/  */

