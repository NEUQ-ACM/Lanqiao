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
	for(int i=2,j=2;j<N;i++) 
	{
		for(int k=0;k<g[i]&&j<N;k++)
		{
			g[j++]=i;
		}
	}
	ll s=0,t=0;
	for(int i=1;i<N;i++)
	{
		s+=i*(ll)g[i];
		if(s>=n) 
		{
			s-=i*(ll)g[i];
			cout<<t+(n-s+i-1)/i<<endl;
			break;
		}
		t+=g[i];
	}
	return 0;
}
