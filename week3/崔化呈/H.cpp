#include<bits/stdc++.h>
using namespace std;
struct stu
{
	int s;
	int a;
	int e;
	int sum;
};
bool cmp(stu x,stu y)
{
	return x.sum<y.sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	stu stun[1000];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&stun[i].s,&stun[i].a,&stun[i].e);
		stun[i].sum=stun[i].s+stun[i].a+stun[i].e;
	}
	sort(stun,stun+n,cmp);
	long long ans=0,t=0;
	for(int i=0;i<n;i++)
	{
		t=t+stun[i].s+stun[i].a;
		ans=ans+t;
		t+=stun[i].e;
	}
	printf("%lld",ans);
}
