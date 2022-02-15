#include<bits/stdc++.h>
using namespace std;

//因为N可能达到100000，所以之能一层循环 
//如何保证每一时刻每家店若无订单，优先级减一呢？
//只能记录上一次有订单距离这次有多远。 

//如果以结构体或pair存订单，cun[N]最后再排序; 2*N大小 
//如果是把vector<int> cun[N] 每个时间点对应几个外卖店 空间占用更大 
//**********正是由于存储方式不同导致时间复杂度的不同！！！因为需要将所有订单处理一遍！
const int N = 100005;
typedef pair<int, int> pir; 

int main() {
	int res = 0;
	int n, m, t;//n个外卖店，m行，当t时刻
	cin >> n >> m >> t;
	vector<pair<int,int> > val(m);//val记录订单
	vector<int> shop(n, 0);//shop记录每家店此时的优先级 
	vector<bool> judge(n, false);//judge记录每家店此时是否加入缓存
	vector<int> record(n, 0);//record记录上一次有订单是什么时间 
	 
	int ts, id;
	for(int i = 0; i < m; i++){
		cin >> ts >> id;
		val[i] = pir(ts,id);
	} 
	sort(val.begin(), val.end());
//	for(int i = 0; i < m; i++){
//		cout << val[i].first << " " << val[i].second << endl;
//	}
	
	for(int i = 0; i < m; i++){
		int t = val[i].first, d = val[i].second;//t时刻d外卖店
		if(t != record[d]) shop[d] = shop[d] - (t-record[d]-1);
		if(shop[d] < 0){
			shop[d] = 0;
		}
		if(judge[d] && shop[d] <= 3){
			judge[d] = false;
			res --;
		} 
		record[d] = t;
		shop[d] += 2;
		if(!judge[d] && shop[d] > 5) judge[d] = true, res++;
	}
	for(int i = 1; i <= n; i++){
		if(record[i] != t){
			shop[i] = shop[i] - (t - record[i]);
		}
		if(judge[i] && shop[i] <= 3) res--;
	}
	cout << res;
}
/*
1 5 10
1 1
2 1
3 1
4 1
5 1

*/


