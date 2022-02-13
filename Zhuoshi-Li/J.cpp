#include <bits/stdc++.h>
using namespace std;

const int N = 135, M = 10010;

int f[N][30][N];
//chcnt[i][j]记录第i个位置取字母j+'a'的逆序对最大值 
int chcnt[N][30];
//mlen[i]记录每个位置的最大值 
int mlen[N];

void dp()
{
	for (int i = 2; i < N; ++i)
	{
		int m = 0;
		for (int j = 1; j <= 'z' - 'a'; ++j)
		{
			for (int k = 1; k < i; ++k)
			{
				if (k > 1) f[i][j][k] = f[i - 1][j][k - 1] + i - k;
				else f[i][j][k] = chcnt[i - 1][j - 1] + i - 1;
				chcnt[i][j] = max(chcnt[i][j], f[i][j][k]);
			}
			m = max(m, chcnt[i][j]);
		}
		mlen[i] = m;
	}

}

int main()
{
	dp();

	int score = 0;
	cin >> score;
	//找出最短长度值
	int beg = 0;
	for (int i = 1; i < N; ++i)
		if (mlen[i] >= score)
		{
			beg = i;
			break;
		}

	int curr = 0;	//用于记录逆序值
	int same = 1;	//记录后缀中有多少个相同字母
	char last = 'z' + 1;//记录上一个字母是什么 
	for (int i = beg; i > 0; --i)
	{
		//从a开始枚举
		int j = 0;
		for (; j <= last - 'a'; ++j)
		{
			if (j == last - 'a') curr -= same;
			if (curr + chcnt[i][j] >= score)
			{
				curr += i - 1;
				break;
			}
		}
		if (j == last - 'a') same++;
		else
		{
			last = j + 'a';
			same = 1;
		}
		cout << last;
	}
	cout << endl;

	return 0;
}

