#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int maxx=-1,minn=101,mm;
	double summ;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&mm);
		maxx=maxx>mm?maxx:mm;
		minn=minn<mm?minn:mm;
		summ+=mm;
	}
	printf("%d\n%d\n",maxx,minn);
	cout<<fixed<<setprecision(2)<<summ*1.00/n<<endl;
	return 0;
}
