/*第二题跟第一题类似
显然，行列以及对角线上的和为34
但是如果偷懒用枚举全排列解决 
15! = 1307674368000 , 亲测跑了好久也不出结果 

#include<bits/stdc++.h>
using namespace std;
int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},cnt; 
long long k = 1307674368000;
int main(){
	while(k--) {
		next_permutation(a+1,a+16);
		bool flag = 0;
		int num = a[0]+a[5]+a[10]+a[15]; //主对角线 
		int tmp = a[3]+a[6]+a[9]+a[12]; //副对角线 
		if(tmp!=num) continue;
		for(int i=0; i<=12; i+=4) { //判断每一行 
			int tmp = a[i]+a[i+1]+a[i+2]+a[i+3];
			if(tmp!=num) {flag=1;break;} 
		} if(flag==1) continue;
		for(int i=0; i<=3; i++) { //判断每一列 
			int tmp = a[i]+a[i+4]+a[i+8]+a[i+12];
			if(tmp!=num) {flag=1;break;} 
		} if(flag==1) continue;
		cnt++;
	} printf("%d\n",cnt); 
    return 0;
}

那么我们不偷懒，用dfs来找全排列 
就可以在写dfs的时候加剪枝来提高速度 
*/

#include<bits/stdc++.h>
using namespace std;
bool vis[17];
int a[4][4],cnt;
bool check(int x,int y) {
    if(x<3) {
        if(y<3) return 1;
        if(a[x][0]+a[x][1]+a[x][2]+a[x][3]==34) return 1;
        return 0;
    } else {
        if(y==0) {
            if(a[0][0]+a[1][0]+a[2][0]+a[3][0]!=34) return 0;
			if(a[0][3]+a[1][2]+a[2][1]+a[3][0]!=34) return 0;
        } else if(y==1||y==2) {
            if(a[0][y]+a[1][y]+a[2][y]+a[3][y]!=34) return 0;
        } else{
            if(a[0][3]+a[1][3]+a[2][3]+a[3][3]!=34) return 0;
			if(a[0][0]+a[1][1]+a[2][2]+a[3][3]!=34) return 0;
        }
        return 1;
    }
}

void dfs(int x,int y) {
    if(x==4) { cnt++; return; }
    for(int i=1; i<=16; i++)
        if(!vis[i]) {
            vis[i] = 1;
            a[x][y] = i;
            if(check(x,y)) {
                if(y<3) dfs(x,y+1);
                else dfs(x+1,0);
            }
            vis[i] = 0;
        }
}

int main() {
    vis[1] = true;
    a[0][0] = 1;
    dfs(0,1);  
    printf("%d\n",cnt);
    return 0;
}
