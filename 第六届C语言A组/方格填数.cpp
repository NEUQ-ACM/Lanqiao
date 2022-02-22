#include<iostream>
#include<vector>
using namespace std;
vector<int> repeat(11,0);
int map[2][5];
int ansnumber=0;
void dfs(int n);
int main()
{
	dfs(0);
	cout<<ansnumber;
	return 0;
}
void dfs(int n)
{
	if(n<=9)
	{
		int l=n/5;
		int c=n%5;
		for(int i=1;i<=10;i++)
		{
			if(repeat[i]==0&&((l==0)||(l==1&&i>map[l-1][c]))&&((c==0)||((c>=1&&c<=9)&&i>map[l][c-1])))
			{
				map[l][c]=i;
				repeat[i]++;
				dfs(n+1);
				repeat[i]=0;
			}
		}
	}
	else if(n==10)
	{
		ansnumber++;
		for(int i=0;i<=1;i++)
		{
			for(int j=0;j<=4;j++)
			{
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return;
	}
}
