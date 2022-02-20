#include <bits/stdc++.h>
using namespace std;
int days[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(int year){
	return year% 400==0 || year% 4==0 && year% 100!=0;
}
int get_day(int year,int month){
	if(month==2) return 28+check(year);
	return days[month];
}
int main(){
	int n,flag1=0,flag2=0;;
	cin>>n;
	string ans1,ans2;
	for(int i=n/10000;i<10000;i++){
		string a=to_string(i);
		string b=a;
		reverse(b.begin(),b.end());
		int month=stoi(b.substr(0,2)),day=stoi(b.substr(2,2));
		if(a+b<=to_string(n) || month<1 || month>12 || day<1 || day>get_day(i,month)) continue;
		string s1=a.substr(0,2);
		string s2=a.substr(2,2);
		if(!flag1) ans1=a+b,flag1=1;
		if(!flag2 && s1==s2 && s1[0]!=s1[1]) ans2=a+b,flag2=1;
		if(flag1 && flag2) break;
	}
	cout<<ans1<<endl<<ans2<<endl;
}
