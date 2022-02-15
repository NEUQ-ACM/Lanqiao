#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int n,m;
int a[100005];
int w[100005];
void mergeSortHigh(int arr[],int l,int mid,int r)
{
	int left=l,right=mid+1;
	int len=r-l+1;
	int i=0;
	while(left<=mid&&right<=r)
	{
		if(arr[left]<=arr[right])
		{
			w[++i]=arr[left++];
		}
		else w[++i]=arr[right++];
	}
	while(left<=mid)w[++i]=arr[left++];
	while(right<=r)w[++i]=arr[right++];
	for(int i=1;i<=len;i++)
	{
		arr[l+i-1]=w[i];
	}
}
void mergeHigh(int arr[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	mergeHigh(arr,l,mid);
	mergeHigh(arr,mid+1,r);
	mergeSortHigh(arr,l,mid,r);
}

void mergeSortLow(int arr[],int l,int mid,int r)
{
	int left=l,right=mid+1;
	int len=r-l+1;
	int i=0;
	while(left<=mid&&right<=r)
	{
		if(arr[left]>=arr[right])
		{
			w[++i]=arr[left++];
		}
		else w[++i]=arr[right++];
	}
	while(left<=mid)w[++i]=arr[left++];
	while(right<=r)w[++i]=arr[right++];
	for(int i=1;i<=len;i++)
	{
		arr[l+i-1]=w[i];
	}
}
void mergeLow(int arr[],int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;
	mergeLow(arr,l,mid);
	mergeLow(arr,mid+1,r);
	mergeSortLow(arr,l,mid,r);
}
pair<int,int>x[100005];
int top=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int p,q;
		cin>>p>>q;
		if(top==0)
		{
			x[++top]={p,q};
		}
		else
		{
			if(p==0)
			{
				if(x[top].first==0&&q>x[top].second)
				{
					x[top]={p,q};
				}
				else if(x[top].first==0&&q<=x[top].second)continue;
				else if(x[top].first==1)
				{
					x[++top]={p,q};
				}
			}
			else if(p==1)
			{
				if(x[top].first==1&&q<x[top].second)
				{
					x[top]={p,q};
				}
				else if(x[top].first==1&&q>=x[top].second)continue;
				else if(x[top].first==0)
				{
					x[++top]={p,q};
				}
			}
		}
	}
	for(int i=1;i<=top;i++)
	{
		if(x[i].first==0)
		{
			mergeLow(a,1,x[i].second);
		}
		else
		{
			mergeHigh(a,x[i].second,n);
		}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
