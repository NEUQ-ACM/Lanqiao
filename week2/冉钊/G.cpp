#include<bits/stdc++.h>
using namespace std;
int N;
vector<int >dates;
vector<int >ABdates;
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void check(int year){
    int a = year/ 1000;
	int b = year / 100 % 10;
	int c = year % 100 / 10;
	int d = year % 10;
	int month = d * 10 + c;
	int day = b * 10 + a;
	if (month == 0 || month > 12) return;
	if (day > days[month]) return;
	int t = year * 10000 + d * 1000 + c * 100 + b * 10 + a;
	dates .push_back(t);
	if (a == c && b == d) ABdates.push_back(t);
	return;
}
int findAB(vector<int >ABdates,int x){
    int l = 0;
    int r=ABdates.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(ABdates[mid]<=x){
            l=mid+1;
        }else{
            ans=ABdates[mid];
            r=mid-1;
        }
    }
    return ans;
}
int find(vector<int >dates,int x){
    int l = 0;
    int r=dates.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(dates[mid]<=x){
            l=mid+1;
        }else{
            ans=dates[mid];
            r=mid-1;
        }
    }
    return ans;
}
int  main(){
    ios::sync_with_stdio(false);
    for(int i=1000;i<=9090;i++){
        check(i);
    }
    cin>>N;
    cout<<find(dates,N)<<endl<<findAB(ABdates,N)<<endl;
    return 0;
}