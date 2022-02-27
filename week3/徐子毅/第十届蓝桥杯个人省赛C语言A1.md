1、朴素算法，直接上。

```C++
#include <iostream>
#include <cstring>
using namespace std;
bool has2019(int num){
    string the_num=to_string(num);
    for(int i=0;i<the_num.size();i++){
        if(the_num[i]=='0'||the_num[i]=='2'||the_num[i]=='1'||the_num[i]=='9') return true;
    }
    return false;
}
int main(){
    long long sum=0;
    for(int i=1;i<=2019;i++){
        if(has2019(i)) sum+=i*i;
    }
    cout << sum << endl;
}
```

2、这里是一个递归，因为开20000000的数组太大了，所以这里可以只开4个数组，轮流相加（全加再减去当前www）。

```C++
#include <iostream>
using namespace std;
long long a[4]={1,1,1,3};
int main(){
	long long count=4;
	int i=0;
	while(count!=20190324){
		count++;
		a[i]=(a[0]+a[1]+a[2]+a[3]-a[i])%10000;
		if(i==3) i=0;
		else i++;
	}
	cout << i << endl;
	cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << endl;
}
```

3、这直接用数学解了，画个7x7的图，再发现中间的是答案。所以把7x7分为4个区块，右下角的区块是比答案大的。所以答案最多的是49-15=34。

4、一个bfs,正常的bfs.

```C++
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,0};
int map[35][55];
int vis[35][55]={0};
char ch[4]={'D','U','L','R'};
struct Point{
	int x;
	int y;
	string step;
};
queue<Point> que;
int main(){
	Point start;
	vis[0][0]=1;
	start.x=0;start.y=0;start.step="";
	for(int i=0;i<30;i++) for(int j=0;j<50;j++){
		cin >> map[i][j];
	}
	que.push(start);
	bool found=false;
	while(!que.empty()||found){
		Point setup=que.front();
		for(int i=0;i<4;i++){
			Point next;
			next.x=setup.x+dx[i];
			next.y=setup.y+dy[i];
			next.step=setup.step+ch[i];
			if(next.x==29&&next.y==49){
				cout << next.step << endl;
				found=true;
			}
			if(vis[next.x][next.y]==0||next.x<30||next.y<50||map[next.x][next.y]==0){
				que.push(next);
				vis[next.x][next.y]=1;
			}
		}
		que.pop();
	}
}
```

6、看起来是二叉树，其实就是一个简单的数学，1 2 4 8 ......相加即可。

```C++
#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int nums=1;
	int deeps=1;
	int maxdeeps=0;
	int max=0;
	int p=0;
	while(p<n){
		int sum=0;
		while(nums--){
			if(p>=n) break;
			sum+=a[p];
			p++;
		}
		if(sum>max){
			max=sum;
			maxdeeps=deeps;
		}
		deeps++;
		nums*=2;
	}
	cout << maxdeeps << endl;
}
```

7、模拟一下就可以得出结果了www。

```C++
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
struct D{
	int ts;
	int id;
};
bool cmp(const D &d1,const D &d2){
	if(d1.ts<d2.ts) return true;
	else return false;
}
int main(){
	int N,M,T;
	cin >> N >> M >> T;
	int a[N];
	int vip[N];
	D dd[M];
	for(int i=0;i<N;i++) a[i]=0;
	for(int i=0;i<M;i++){
		int ts,id;
		cin >> ts >> id;
		dd[i].ts=ts;
		dd[i].id=id-1;
	}
	for(int i=1;i<=T;i++){
		for(int j=0;j<M;j++){
			if(dd[j].ts==i) {
				a[dd[j].id]+=3;
				if(a[dd[j].id]>6) vip[dd[j].id]=1;
			}
		}
		for(int j=0;j<N;j++){
			if(a[j]>0) a[j]--;
			if(a[j]<=3) vip[j]=0;
		}
	}
	int sum=0;
	for(int i=0;i<N;i++) if(vip[i]==1) sum++;
	cout << sum << endl;
}
```

