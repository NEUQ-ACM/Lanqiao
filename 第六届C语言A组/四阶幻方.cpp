#include<iostream>
using namespace std;
int repeat[17];
int map[4][4];
int sum=0;
int ans=0;
void dfs(int n);
int main()
{
	map[0][0]=1;
	sum=sum+1;
	dfs(1);
	cout<<ans;//416
	return 0;
}
void dfs(int n)
{
	if(n<=15)
	{
		int l=n/4;
		int c=n%4;
		for(int i=2;i<=16;i++)
		{
			if(repeat[i]==0)
			{
				if(l==0)
				{
					map[l][c]=i;
					repeat[i]++;
					sum=sum+i;
					dfs(n+1);
					repeat[i]=0;
					sum=sum-i;
				}
				else if(l==1||l==2)
				{
					if(c!=3)
					{
						map[l][c]=i;
						repeat[i]++;
						dfs(n+1);
						repeat[i]=0;
					}
					else
					{
						if(map[l][0]+map[l][1]+map[l][2]+i==sum)
						{
							map[l][c]=i;
							repeat[i]++;
							dfs(n+1);
							repeat[i]=0;
						}
					}
				}
				else if(l==3)
				{
					if(c==0)
					{
						if(map[0][c]+map[1][c]+map[2][c]+i==sum&&map[0][3]+map[1][2]+map[2][1]+i==sum)
						{
							map[l][c]=i;
							repeat[i]++;
							dfs(n+1);
							repeat[i]=0;
						}
					}
					else if(c==1||c==2)
					{
						if(map[0][c]+map[1][c]+map[2][c]+i==sum)
						{
							map[l][c]=i;
							repeat[i]++;
							dfs(n+1);
							repeat[i]=0;
						}
					}
					else
					{
						if(map[l][0]+map[l][1]+map[l][2]+i==sum&&map[0][c]+map[1][c]+map[2][c]+i==sum&&map[0][0]+map[1][1]+map[2][2]+i==sum)
						{
							map[l][c]=i;
							repeat[i]++;
							dfs(n+1);
							repeat[i]=0;
						}
					}
				}
			}
		}
	}
	else if(n==16)
	{
		for(int i=0;i<=3;i++)
		{
			for(int j=0;j<=3;j++)
			{
				cout<<map[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		ans++;
		return;
	}
}
