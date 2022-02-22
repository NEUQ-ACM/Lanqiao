1.
42
´úÂë£º
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

2.
416
´úÂë£º
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

3.
if(me->r) printInBuf(me->r,buf,p3,y+2);

4.
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

5.
#include<iostream>
#include<cstring>
#include<set>
const int maxn=1e5+5;
typedef long long ll;
using namespace std;
bool is_return(string s){
	int len = s.length() ;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])
			return false;
	}
	return true;
}     
int re[maxn],not_re[maxn];
set<string> e1,e2;
int main(){
	int n,temp;
	bool flag;
	scanf("%d",&n);
	string str,tmp;
	cin>>str;
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j-=2){
			temp=i-j+1;
			tmp=str.substr(j,temp);
			flag=is_return(tmp);
			if(flag)
				e1.insert(tmp); 
		} 
		re[i]=e1.size() ;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			flag=false;
			temp=j-i+1;
			tmp=str.substr(i,temp);
			if(tmp.length() %2){
				if(is_return(tmp)  )
					flag=true;
			} 
			if(!flag){
				e2.insert(tmp); 
			}
		} 
		not_re[i]=e2.size() ;
	}
	int ans=0;
	for(int i=1;i<n;i++){
		ans=max(ans,re[i-1]*not_re[i]);
	}
	printf("%d\n",ans);
	return 0;
}