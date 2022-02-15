#include<bits/stdc++.h>
using namespace std;
vector< pair<double,double> >re;//k,b->是否标记
bool check(double k,double b)
{
	for(auto &it:re)
	{
		if(it.first==k&&it.second==b) return 0;
	}
	return 1;
}
int main()
{
	int sum=0;
	int mx=20,my=21;
	for(int i=0;i<mx-1;i++)
	{
		for(int j=0;j<my;j++)//枚举点
		{
			for(int x=i+1;x<mx;x++)
			{
				for(int y=0;y<my;y++)//枚举连接的点
				{
					if(j==y) continue;
					double k=1.0*(j-y)/(i-x);
					double b=y-k*x;
					if(check(k,b))
					{
						re.push_back(make_pair(k,b));//插入
						sum++;
					}
				}
			}
		}
	}
	sum=sum+mx+my;
	cout<<sum;
    return 0;
}
