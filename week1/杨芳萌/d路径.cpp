/*一开始我在想，这个题好可怕，要建好多边
后来一想，就算是2021^2也不过4e4多点
所以把这个题当成模拟硬做就行了
答案是10266837*/
#include<bits/stdc++.h>
using namespace std;
int cnt,n=2021,first[100000],dist[2333];
bool r[2333];
int gcd(int a, int b) { return b?gcd(b,a%b):a; } 
int lcm(int a, int b) { return a/gcd(a,b)*b; }

struct edge{
	int end,nxt,len;
}bian[123456];

void addedge(int s,int e,int w){
	cnt++;
	bian[cnt].end = e;
	bian[cnt].len = w;
	bian[cnt].nxt = first[s];
	first[s] = cnt;
} 

priority_queue<pair<int,int> > heap;
void dij(int s) {
	memset(dist,0x3f,sizeof(dist));
	dist[s] = 0;
	for(int i=1; i<=n; i++) heap.push(make_pair(-dist[i],i));
	for(int i=1; i<=n; i++) {
		while(r[heap.top().second]) heap.pop();
		int p = heap.top().second;
		r[p] = true;
		heap.pop();
		for(int x=first[p]; x!=0; x=bian[x].nxt){
			int end = bian[x].end;
			int len = bian[x].len;
			int newd = dist[p]+len;
			if(newd<dist[end]){
				dist[end] = newd;
				heap.push(make_pair(-dist[end],end));
			}
		}
	}
}

int main() {
	for(int i=1; i<=n; i++) 
		for(int j=i+1; j<=i+21; j++) {
			int tmp = lcm(i,j);
			addedge(i,j,tmp);
			addedge(j,i,tmp);
		}
	dij(1);
	printf("%d\n",dist[2021]);
    return 0;
}

