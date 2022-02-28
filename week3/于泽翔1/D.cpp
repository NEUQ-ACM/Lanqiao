#include<bits/stdc++.h>
using namespace std;

bool v[7][7]={0}, vis[7]={1};
int ans=0;
set<set<int> > ST;
void add(int a, int b)
{
	v[a][b]=v[b][a]=1;
}

void dfs(int x, set<int> s)
{
	if(!ST.count(s))
	{
		ST.insert(s);
		ans++;
	}
	if(s.size()==7)
		return;
		
	for(int j=0;j<7;j++)
	{
		if(vis[j]||!v[x][j])
		continue;
		
		s.insert(j);
		vis[j]=1;
		dfs(j,s);
		vis[j]=0;
		s.erase(j);
	}
}

int main(void)
{
	add(0, 1), add(0, 2), add(1, 3), add(2, 4), add(2, 3), add(3, 5), add(4, 5);
	set<int> S;
	for(int i=0; i<=6; i++)
	{
		S.insert(i);
		dfs(i, S);
		vis[i]=0;
		S.erase(i);
	}
	cout<<ans;
	
	return 0;
}