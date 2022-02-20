#include<iostream>
#include<vector>
using namespace std;
struct Tree
{
	int father;
	vector<int>Son;
	int maxhigh;
};
Tree T[100001];
int main()
{
	int n, i, father, high = 0;
	cin >> n;
	T[1].maxhigh = 0;
	for (i = 2; i <= n; i++)
	{
		cin >> father;
		T[father].Son.push_back(i);
		T[i].father = father;
	}
	for (i = 2; i <= n; i++)
	{
		T[i].maxhigh = T[T[i].father].maxhigh + T[T[i].father].Son.size();
		if (T[i].maxhigh > high) high = T[i].maxhigh;
	}
	cout << high << endl;
	return 0;
}