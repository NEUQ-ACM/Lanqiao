#include<iostream>
using namespace std;

int a[1001][1001];

int main()
{
	int cnt=1;
	int i=1,j=1;
	a[i][j]=cnt;
	while(cnt<10000)
	{

		if(i==1)
			j++;
		a[i][j]=++cnt;
		while(j>1)
			a[++i][--j]=++cnt;
		if(j==1)
			i++;
		a[i][j]=++cnt;
		while(i>1)
			a[--i][++j]=++cnt;
	}
	cout<<a[20][20];
	return 0;
}
