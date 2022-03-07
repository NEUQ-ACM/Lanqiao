#include<bits/stdc++.h>
using namespace std;
const int hang = 30 ,lie = 50;
bool myMap[100][100];
bool vst[100][100];
string d = "DLRU";
int cpass[4][2] = {1,0,0,-1,0,1,-1,0};
struct node{
    int x,y;
    string ans;
};
bool check(int x,int y){
    if(x<1 || y<1 || x>30 || y>50) return false;
    else if(vst[x][y]==1 || myMap[x][y]==1) return false;
    else return true; 
}
void bfs(){
    struct node start;
    start.x = 1;
    start.y = 1;
    start.ans = "";

    queue <node> q;
    q.push(start);
    struct node temp,nex;

    while(!q.empty()){
        temp = q.front();
        q.pop();
        vst[temp.x][temp.y]=1;
        for(int i=0;i<4;i++){
            nex.x=temp.x+cpass[i][0];
            nex.y=temp.y+cpass[i][1];
            nex.ans=temp.ans+d[i];
            if(check(nex.x,nex.y)){
                q.push(nex);
                if(nex.x == hang && nex.y ==lie ){
                cout<<nex.ans<<endl;
                return ;
                }
            }
        }
    }
}
void input(){
    for(int i = 1;i <= 30;i++){
        for(int j = 1;j <= 50;j++){
            char ch = getchar();
            while(ch!='0' && ch!='1'){
                ch = getchar();
            }
            myMap[i][j] = (ch == '1');
        }
    }
}
int main(){
    input();
    bfs();
    return 0;
}