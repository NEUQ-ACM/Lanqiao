#include <iostream>
#include <math.h>
using namespace std;

int len = 7;
int tree[100005] = {0,1,6,5,4,3,2,1};

int main()
{
    //cin>>len;
	//for(int i = 1;i <= len;i++) cin>>tree[len];
	int max = tree[1],ans = 1;
	int begin = 2;
	for(int i = 2;begin <= len;i++){
		int sum = 0;
		int end = begin * 2 > len ? (len + 1) : begin * 2;
		for(int j = begin;j < end;i++)sum += tree[i];
		if(sum > max) ans = i;
		begin = end;
	}
	cout<<ans;
}