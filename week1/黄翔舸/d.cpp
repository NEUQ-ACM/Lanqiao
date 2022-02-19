
#include<iostream>
#define ll long long
using namespace std;
int gsq(int x, int y)
{
	return y == 0 ? x : gsq(y, x % y);
}
int llm(int x, int y)
{
	return x * y / gsq(x, y);
}
int dis[3000];
int main()
{
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	for (int i = 1; i <= 2021; i++)
		for (int j = i + 1; j <= 2021 && j - i <= 21; j++)
			dis[j] = min(dis[j], llm(i, j) + dis[i]);
	cout << dis[2021] << endl;
}
