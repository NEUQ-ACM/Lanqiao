#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int INF = 65535;
int n,m;
int r[maxn][maxn],s[maxn][maxn];//某个点到起点的消耗最少能量
bool v[maxn][maxn];
const int f[4][2]={{-1,0},{0,-1},{0,1},{1,0}};//移动 D<L<R<U
string pa;//路径字符串
struct node
{
	int x,y;
};
bool check(int x,int y)//该点是否合法
{
	if(x<0||x>=n||y<0||y>=m||r[x][y]==1) return 0;
	return 1;
}
void bfs(int sx,int sy,int ex,int ey)
{
	queue<node>q;
	node sta,next;
	sta.x=sx;sta.y=sy;
	q.push(sta);
	while(!q.empty())
	{
		sta=q.front();
		q.pop();
		v[sta.x][sta.y]=1;//标记已处理
		
		//cout<<sta.x<<" "<<sta.y<<" "<<s[sta.x][sta.y]<<endl;//输出路径
		
		for(int i=0;i<4;i++)
		{
			next.x=sta.x+f[i][0];
			next.y=sta.y+f[i][1];
			if(check(next.x,next.y)&&!v[next.x][next.y])
			{
				v[next.x][next.y]=1;//标记已处理
				s[next.x][next.y]+=s[sta.x][sta.y];//
				q.push(next);
			}
		}
	}
}
void putpath(int ex,int ey,int sx,int sy)//从终点开始打印
{
	if(ex==sx&&ey==sy) return;
	int x,y;
	int ansx=ex,ansy=ey,minn=INF;
	int flag;//判断上下左右
	for(int i=3;i>=0;i--)//从终点反着来所以移动顺序相反
	{
		x=ex+f[i][0];
		y=ey+f[i][1];
		if(minn>s[x][y]&&check(x,y))
		{
			minn=s[x][y];ansx=x;ansy=y;
			flag=i;
		}
	}
	if(flag==3) pa="U"+pa;
	else if(flag==2) pa="L"+pa;
	else if(flag==1) pa="R"+pa;
	else if(flag==0) pa="D"+pa;
	putpath(ansx,ansy,sx,sy);
}
int main()
{
	memset(v,0,sizeof(v));
	int stax=0,stay=0,endx=29,endy=49;
	n=30;m=50;
	string str;//一行字符串
	for(int i =0;i<n;i++)
	{
		cin>>str;
		for(int j =0;j<m;j++)
		{
			r[i][j]=str[j]-'0';
			s[i][j]=1;
			if(r[i][j]==1) v[i][j]=1;//标记
		}
	}
	bfs(stax,stay,endx,endy);
	putpath(endx,endy,stax,stay);
	cout<<pa;
	return 0;
}
/*小型测试数据
5 5
1 3 3 3
-1 -1 -1 -1 -1
-1  2  1  1 -1
-1  0 -1 -1 -1
-1  2  1  1 -1
-1 -1 -1 -1 -1
*/