#include <bits/stdc++.h>
#define MP make_pair
using namespace std;
char a[32][52];
bool vis[32][52];
char s[] = "DLRU";
int dx[] = { 1, 0, 0,-1};
int dy[] = { 0,-1, 1, 0};
bool ok(int x,int y)
{
   return x>=0&&x<30&&y>=0&&y<50&&!vis[x][y]&&a[x][y]=='0'; 
} 
int r[32][52];
void bfs()
{
   memset(vis,false,sizeof(vis));
   queue<pair<int,int> > Q;
   Q.push(MP(0,0));
   vis[0][0] = true;
   int x,y,xx,yy;
   while(!Q.empty())
   {
   	x = Q.front().first, 
   	y = Q.front().second;
    	Q.pop();
   	for(int i=0;i<4;++i)
   	{
   	    xx = x+dx[i];
               yy = y+dy[i];
   	    if(ok(xx,yy)) 
   	   {
   	       vis[xx][yy] = true;
   	       Q.push(MP(xx,yy));
   	       r[xx][yy] = i;
   	   }
    }
   }
   stack<char> St;
   x = 29,y=49;
   while(1)
   {
   	St.push(s[r[x][y]]);
    	xx = x - dx[r[x][y]];
    	yy = y - dy[r[x][y]];
   	x = xx, y = yy;
           if(x==0&&y==0) break;
   } 
   while(!St.empty())
       putchar(St.top()),St.pop();
   puts("");
}
int main()
{
   int n = 0,m;
   for(int i=0;i<30;++i)
    cin>>a[i];
   bfs();
   return 0; 
} 
