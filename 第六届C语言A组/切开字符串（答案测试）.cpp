#include<iostream>
#include<cstring>
#include<set>
const int maxn=1e5+5;
typedef long long ll;
using namespace std;
bool is_return(string s){
	int len = s.length() ;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])
			return false;
	}
	return true;
}     
int re[maxn],not_re[maxn];
set<string> e1,e2;
int main(){
	int n,temp;
	bool flag;
	scanf("%d",&n);
	string str,tmp;
	cin>>str;
	for(int i=0;i<n;i++){
		for(int j=i;j>=0;j-=2){
			temp=i-j+1;
			tmp=str.substr(j,temp);
			flag=is_return(tmp);
			if(flag)
				e1.insert(tmp); 
		} 
		re[i]=e1.size() ;
	}
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<n;j++){
			flag=false;
			temp=j-i+1;
			tmp=str.substr(i,temp);
			if(tmp.length() %2){
				if(is_return(tmp)  )
					flag=true;
			} 
			if(!flag){
				e2.insert(tmp); 
			}
		} 
		not_re[i]=e2.size() ;
	}
	int ans=0;
	for(int i=1;i<n;i++){
		ans=max(ans,re[i-1]*not_re[i]);
	}
	printf("%d\n",ans);
	return 0;
}
