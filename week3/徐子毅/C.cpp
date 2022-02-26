#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int day[49];
int main(){
	int _max=0;
	for(int i=0;i<49;i++) day[i]=i+1;
	while(next_permutation(day,day+49)){
		int result[49];
		memcpy(result,day,49*sizeof(int));
		for(int i=0;i<=42;i+=7){
			sort(result+i,result+i+7);
		}
		int sum=0;
		for(int i=3;i<49;i+=7){
			sum+=result[i];
		}
		_max=max(_max,sum);
	}
	cout << _max << endl;
}