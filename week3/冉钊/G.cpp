#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
vector<int > order[maxn];
int n,m,t;
int ts,id;
int ans;
bool flag=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m>>t;
    for(int i=1;i<=m;i++){
        cin>>ts>>id;
        if(ts<=t && ts>=0){
            order[id].push_back(ts);
        }
    }
    for(int i=1;i<=n;i++){
        flag=0;
        if(!order[i].empty()){
            sort(order[i].begin(),order[i].end());
            int temp = 0;
            //在进行判断时,应当先加,然后测试一次,再减,然后再测试一次,不然可能出现本因纳入优先,且到下一次订单没有小于等于3不会被清除,却没有纳入优先的情况;
            for(int j=0;j<order[i].size()-1;j++){
                int temp2 = order[i][j+1]-order[i][j];
                if(temp2>=1){
                    temp+=2;

                    if(temp<0)temp=0;
                    if(temp>5 && flag==0){ans++;flag=1;}
                    if(temp<=3 && flag==1){ans--;flag=0;}

                    temp += -temp2+1;

                    if(temp<0)temp=0;
                    if(temp>5 && flag==0){ans++;flag=1;}
                    if(temp<=3 && flag==1){ans--;flag=0;}
                }
                else if(temp2==0){
                    temp+=2;

                    if(temp<0)temp=0;
                    if(temp>5 && flag==0){ans++;flag=1;}
                    if(temp<=3 && flag==1){ans--;flag=0;}
                }else;
            }
            //对最后一次进行特判
                int temp2 = t-order[i][order[i].size()-1];
                if(temp2==0){
                	temp+=2;

                    if(temp<0)temp=0;
                    if(temp>5 && flag==0){ans++;flag=1;}
                    if(temp<=3 && flag==1){ans--;flag=0;}
                }
				else if(temp2>=1){
					temp+=2;

                    if(temp<0)temp=0;
                    if(temp>5 && flag==0){ans++;flag=1;}
                    if(temp<=3 && flag==1){ans--;flag=0;}

                    temp-=temp2;

                    if(temp<0)temp=0;
                    if(temp>5 && flag==0){ans++;flag=1;}
                    if(temp<=3 && flag==1){ans--;flag=0;}
				}else;
        }
    }
    cout<<ans<<endl;
    return 0;
}