#include <bits/stdc++.h>
using namespace std;
int z[10001];
int main()
{
	int n,num;
	vector <int> w;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		w.push_back(a);
	}
	set <int> a;
	vector <int> b;
	b.push_back(w[0]);
	a.insert(w[0]);
	for(int i=1;i<w.size();i++)
	{
		a.insert(w[i]);
		for(int j=0;j<b.size();j++)
		{
			a.insert(w[i]-b[j]);
			a.insert(w[i]+b[j]);
			a.insert(-w[i]-b[j]);
			a.insert(-w[i]+b[j]);
		}
		b.assign(a.begin(),a.end());
	}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]>0) num++;
	}
	cout<<num;
	return 0;
}
