#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> num(n);
	for(int i=0;i<n;i++)
	{
		num[i]=i+1;
	}
	int x=0;
	while (1) 
	{
		x=(x+k-1)%num.size();
		num.erase(num.begin()+x);
		if (num.size() == 1)
		{
			cout << num[0] << endl;
			break;
		}
	}
	return 0;
}
