#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef long long LL;

int day(int y,int m)
{
    int d;
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:d=31;break;
        case 2:{if((!(y%4)&&y%100)||!(y%400)) d=29;
                else d=28;
                break;}
        case 4:
        case 6:
        case 9:
        case 11:d=30;break;
        default:break;
    }
    return d;
}

int main()
{
    int n;
    bool flag=0;
    string ans1,ans2;

    cin>>n;

    for(int i=n/10000;i<10000;i++){
        string a=to_string(i);
        string b=a;
        reverse(b.begin(),b.end());
        if(a+b<=to_string(n)) continue;
        int m=stoi(b.substr(0,2));
        if(m<1||m>12) continue;
        int d=stoi(b.substr(2,2));
        if(d<1||d>day(i,m)) continue;
        if(!flag){
            ans1=a+b;
            flag=1;
        }
        if((m%10==d%10)&&(m/10==d/10)&&(m%10!=m/10)){
            ans2=a+b;
            break;
        }
    }

    cout<<ans1<<endl<<ans2;

    return 0;
}

