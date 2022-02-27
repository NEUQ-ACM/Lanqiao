#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int nums=1;
	int deeps=1;
	int maxdeeps=0;
	int max=0;
	int p=0;
	while(p<n){
		int sum=0;
		while(nums--){
			if(p>=n) break;
			sum+=a[p];
			p++;
		}
		if(sum>max){
			max=sum;
			maxdeeps=deeps;
		}
		deeps++;
		nums*=2;
	}
	cout << maxdeeps << endl;
}