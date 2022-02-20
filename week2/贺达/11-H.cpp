#include<bits/stdc++.h>
#define N 1005
using namespace std;

struct student
{
  int s,a,e;
  int t1,t2;
  //t1为s+a,t2为s+a+e
};

bool cmp(student a,student b)
{
	return a.t2<b.t2;//根据每个学生花费的总时间来排序
}

int main()
{
  int n;
  student st[N];
  cin>>n;

  for(int i=1;i<=n;i++){
    cin>>st[i].s>>st[i].a>>st[i].e;
  	st[i].t1=st[i].a+st[i].s;
    st[i].t2=st[i].t1+st[i].e;
  }

  sort(st+1,st+n+1,cmp);

  long long sum=0,s=0;
  for(int i=1;i<=n;i++)
  {
      sum+=st[i].t1+s;
      s+=st[i].t2;
  }

  cout<<sum<<endl;

  return 0;
}
