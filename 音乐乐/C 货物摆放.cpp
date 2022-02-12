//ans:2430
#include<bits/stdc++.h>
using namespace std;
#define inf 2021041820210418
vector<long long>vec;

int main()
{
	for(int i=1;i<=sqrt(inf);i++)
	{
		if(inf%i==0)
		{
			vec.push_back(i);
			vec.push_back(inf/i);//将所给数的所有约数放入vector容器中，得到一个包含所给数的所有约数的集合 
		}
	}
	int cap=vec.size();
	cout<<cap<<endl;
	int cnt=0;
	for(int i=0;i<cap;i++)
		for(int j=0;j<cap;j++)//枚举集合中两个数的乘积 
			if(inf%(vec[i]*vec[j])==0) cnt++;//如果所给数可以整除这个乘积（所给树是三个数的乘积），计数加一 
	cout<<cnt;
	return 0;
}
