#include<bits/stdc++.h>
using namespace std;
const int N =  10010;
int q[N];
int main()
{
	int average, max, min; 
	float sum = 0
	int n;
	cin>>n;
	max = 0;
	min = 100;
	for(int i = 0;i < n;i++) 
	{
		scanf("%d",&q[i]);
		if(max < q[i]) max = q[i];
		if(min > q[i]) min = q[i];
		sum += q[i];
	}
	cout<<max<<endl;
	cout<<min<<endl;
	cout<<sum / n;
    return 0;
}

