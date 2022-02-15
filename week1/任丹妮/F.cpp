#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn];
int main()
{
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    cin>>a[i];
  }
  int k=log(N+1)/log(2);
  double k1=log(N+1)/log(2);
  if(k<k1) k=k+1;
  long long ANS=a[0],cnt=1;
  int lev=1,ans;
  for(int i=1;i<k-1;i++){
    ans=0;
    for(int j=0;j<pow(2,i);j++){
      ans+=a[cnt+j];
    }
    cnt+=pow(2,i);
    if(ANS<ans) {
      lev=i+1;
      ANS=ans;
    }
  }
  ans=0;
  for(int j=cnt;j<N;j++){
  	ans+=a[j];
  }
  if(ANS<ans) {
      lev=k;
      ANS=ans;
    }
  cout<<lev<<endl;
  return 0;
}
