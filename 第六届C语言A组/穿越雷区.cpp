#include<iostream>
#include<queue>
using namespace std;
class location
{
public:
	int m;
	int n;
	char state;
	location();
	location(int m,int n,char state);
};
char map[102][102];
int judge(location c,char pstate);
int main()
{
	int size;
	cin>>size;
	location A,B;
	for(int i=1;i<=size;i++)
	{
		for(int j=1;j<=size;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='A')
			{
				location temp(i,j,'0');
				A=temp;
			}
			else if(map[i][j]=='B')
			{
				location temp(i,j,'0');
				B=temp;
			}
		}
	}
	for(int j=0;j<=size+1;j++) map[0][j]=map[size+1][j]='*';
	for(int i=1;i<=size;i++) map[i][0]=map[i][size+1]='*';
	queue<location> p;
	p.push(A);
	int ans=-1;
	for(int step=1;step>=1;step++)
	{
		int number=p.size();
		while(number--)
		{
			int m=p.front().m,n=p.front().n;
			char state=p.front().state;
			p.pop();
			location side[4];
			location side1(m+1,n,map[m+1][n]);
			location side2(m-1,n,map[m-1][n]);
			location side3(m,n+1,map[m][n+1]);
			location side4(m,n-1,map[m][n-1]);
			side[0]=side1;
			side[1]=side2;
			side[2]=side3;
			side[3]=side4;
			for(int i=0;i<=3;i++)
			{
				int flag=judge(side[i],state);
				if(flag==0) p.push(side[i]);
				else if(flag==1)
				{
					ans=step;
					goto stop;
				}
			}
		}
		if(p.empty()==1) break;
	}
	stop:;
	cout<<ans;
	return 0;
}
location::location()
{
	m=n=0;
	state='0';
}
location::location(int m,int n,char state)
{
	this->m=m;
	this->n=n;
	this->state=state;
}
int judge(location c,char pstate)
{
	if(pstate==c.state||c.state=='*') return -1;
	else
	{
		if(c.state!='B') return 0;
		else return 1;
	}
}
