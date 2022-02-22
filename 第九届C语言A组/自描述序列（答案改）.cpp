#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1000010;
int g[N];
int main() 
{
	ll n;
	cin>>n;
	g[1]=1,g[2]=2;
	int k=2;
	for(int i=2;i>=2;i++)
	{
		for(int j=1;j<=g[i];j++)
		{
			if(k<N)
			{
				g[k]=i;
				k++;
			}
			else goto stop;
		}
	}
	stop:;
	ll s=0,t=0;
	for(int i=1;i<N;i++)
	{
		s=s+i*(ll)g[i];
		if(s>=n) 
		{
			s=s-i*(ll)g[i];
			cout<<t+(n-s+i-1)/i<<endl;
			break;
		}
		t=t+g[i];
	}
	return 0;
}
