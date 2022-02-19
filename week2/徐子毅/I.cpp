	#include <iostream>
	using namespace std;
	int main(){
		int n,K,ans=0;
		cin >> n >> K;
		int num[n];
		for(int i=0;i<n;i++) cin >> num[i];
		for(int a=0;a<n-2;a++) for(int b=a+1;b<n-1;b++) for(int c=b+1;c<n;c++){
			int sum=num[a]+num[b]+num[c];
			if(sum%K==0) ans=max(ans,sum);
		}
		cout << ans << endl;
		return 0;
	}