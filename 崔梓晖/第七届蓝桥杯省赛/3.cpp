#include<bits/stdc++.h>
using namespace std;
int a[4][4];
int vis[11];
int cnt=0;
bool pd(int x,int y,int v)
{      
    int dir[4][2]={{0,-1},{-1,-1},{-1,0},{-1,1}};   
    for(int i=0;i<4;i++)
	 {         
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(xx<3&&xx>=0&&yy<4&&yy>=0)
		{
            if(abs(a[xx][yy]-v)==1) 
			{
            	return false;           
            }
        }
   }
   return true;
}
void dfs(int x,int y) 
{
    if(x==2&&y==3) 
	{
    	cnt++;   
	    return;
	}
    for(int i=0;i<=9;i++)
	{  
        if(vis[i]==0&&pd(x,y,i))
		{  
            vis[i]=1;
			a[x][y]=i;
            if(y+1<4) 
			{
            	dfs(x,y+1);   
			}else 
			{
				dfs(x+1,0);
		    }
            vis[i]=0;  
        }
    }
    return ;
}
int main()
{
	memset(a,-1,sizeof(a));    
    dfs(0,1);         
    cout<<cnt;
    return 0;
}

