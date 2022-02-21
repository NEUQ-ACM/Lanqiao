#include<bits/stdc++.h>
using namespace std;
bool connect[7][7]={
    {0,1,0,0,0,1,0},
    {1,0,1,0,0,0,1},
    {0,1,0,1,0,0,1},
    {0,0,1,0,1,0,0},
    {0,0,0,1,0,1,1},
    {1,0,0,0,1,0,1},
    {0,1,1,0,1,1,0}
};
inline int isconnect(int S){
    int que[16],Head=0,Tail=0,NS=0;
    bool vis[16]={0};
    for(int i=0;i<7;i++) if( (S>>i)&1 ){
        que[++Tail]=i;
        vis[i]=1;
        break;
    }
    while(Head<Tail){
        int now=que[++Head];
        NS|=1<<now;
        for(int i=0;i<7;i++)
            if( ((S>>i)&1)&&connect[now][i]&&!vis[i] ){
                que[++Tail]=i;
                vis[i]=1;
            }
    }
    return NS==S;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int res=0;
    for(int i=1;!(i>>7);i++) res+=isconnect(i);
    cout<<res;
    cout.flush();
    return 0;
}