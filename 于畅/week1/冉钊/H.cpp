#include<bits/stdc++.h>
using namespace std;
//树的最大高度就是其根结点最大的子树深度加上他的儿子总数
const int maxn=100100;
int N;
int dp[maxn];
vector<vector<int> >son;
void dfs(int root){
    int len = son[root].size();
    int rmax = 0;
    for(int i = 0; i < len;i++){

        dfs(son[root][i]);
        rmax=max(rmax,dp[son[root][i]]);
    }
    dp[root]=len+rmax;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> N;
    son.resize(N+1);
    for(int i = 2;i <= N;i++){
        int temp;
        cin >> temp;
        son[temp].push_back(i);
    }
    dfs(1);
    cout << dp[1];
    return 0;
} 