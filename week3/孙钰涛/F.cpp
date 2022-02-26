#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum[100001],n,temp;
    cin>>n;
	for(int i=1;i<=n;i++)
    {
		cin>>temp;
		int k = log2(i) + 1;
		sum[k]=sum[k]+temp;
	}
	
	int len=log2(n)+1;
	int maxn=0,flag=0;
	for(int i=1;i<=len;i++)
    {
		if(sum[i]>maxn)
        {
			maxn=sum[i];
		 	flag=i;
		}
	}
	cout<<flag<<endl;
	return 0;
}
