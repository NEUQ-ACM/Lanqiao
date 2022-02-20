#include <iostream>
#include <cstring>
using namespace std;
int turn_time_second(){
	char time[30]={};
	cin.getline(time,30);
	int hour1,hour2,minute1,minute2,second1,second2;
	int extend=0;
	if(strlen(time)==22) sscanf(time,"%d:%d:%d %d:%d:%d (+%d)",&hour1,&minute1,&second1,&hour2,&minute2,&second2,&extend);
	else sscanf(time,"%d:%d:%d %d:%d:%d",&hour1,&minute1,&second1,&hour2,&minute2,&second2);
	return (hour2-hour1+extend*24)*60*60+(minute2-minute1)*60+second2-second1;
}
int main(){
	int n;
	cin >> n;
	getchar();
	while(n--){
		int time1=turn_time_second();
		int time2=turn_time_second();
		int time=(time1+time2)/2;
		printf("%02d:%02d:%02d\n",time/60/60,time/60%60,time%60);
	}
}