#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct shop
{
	bool inram=0;
	int prio=0;
	int lastupdate=0;
};

struct order
{
	int ts;
	int id;
};

int main() {
	ios::sync_with_stdio(false);
	int N, M, T;
	cin >> N >> M >> T;
	vector<shop>db(N + 5);
	order temp;
	vector<order>all;
	all.reserve(100005);
	for (size_t i = 0; i < M; i++)
	{
		cin >> temp.ts >> temp.id;
		all.emplace_back(temp);
	}
	sort(all.begin(), all.end(), [](order &o1, order &o2) {return o1.ts < o2.ts; });
	int ram = 0;
	for (auto &c : all) {
		//sync lastupdate
		if (db[c.id].lastupdate < c.ts)db[c.id].prio -= (c.ts - (db[c.id].lastupdate + 1));
		if (db[c.id].prio < 0)db[c.id].prio = 0;
		if (db[c.id].inram && db[c.id].prio <= 3) {
			db[c.id].inram = 0;
			ram -= 1;
		}
		db[c.id].prio += 2;
		if ((!db[c.id].inram) && db[c.id].prio > 5) {
			db[c.id].inram = 1;
			ram += 1;
		}
		db[c.id].lastupdate = c.ts;
	}
	for (auto &c : db) {
		c.prio -= (T - (c.lastupdate));
		if (c.inram && c.prio <= 3) {
			c.inram = 0;
			ram -= 1;
		}
	}
	cout << ram;
}