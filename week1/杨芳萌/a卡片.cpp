/*这个题换个角度理解起来就是，
从1开始数数，数到几的时候，0-9中的一个数出现了2021次
答案是3181*/ 
#include<bits/stdc++.h>
using namespace std;
int num[10],n=1,ans;

int main(){
	do {
		int tmp = n;
		while(tmp) {
			int a = tmp%10;
			num[a] ++;
			if(num[a]==2021) { ans=n; break; }
			tmp /= 10;
		}
		if(ans!=0) break;
	} while(n++);
	printf("%d\n",ans);
    return 0;
}

