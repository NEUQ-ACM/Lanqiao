#include<bits/stdc++.h>
using namespace std;
typedef struct d{
    double x;
    double y;
} d,*linkd;
vector<linkd>dian;
//typedef struct l{
//    double a;
//    double b;
//}l,*linkl;
//vector<linkl>line;
map<pair<double, double>, bool> visit;
long long ans;
void getline(linkd A,linkd B){
	double x1=A->x,x2=B->x;
	double y1=A->y,y2=B->y;  
    double b=(x2 * y1 - y2 * x1) / (x2 - x1);
    double a=(y2 - y1) / (x2 - x1);;
//    for(int i=0;i<line.size();i++){
//        if(fabs(line[i]->a-a)<0.0000001){
//            if(fabs(line[i]->b-b)<0.0000001){
//                linkl temp=new l;
//                temp->a=a;
//                temp->b=b;
//                line.push_back(temp);
//            }
//        }
//    }
	 if (!visit[{a, b}])
    {
        visit[{a, b}] = 1;
        ans++;
    }
}
int main(){
    for(int i=0;i < 20;i++){
        for(int j=0;j < 21;j++){
            linkd temp=new d;
            temp->x=i;
            temp->y=j;
            dian.push_back(temp);
        }
    }
    for(int i=0;i<dian.size();i++){
        for(int j=i+1;j<dian.size();j++){
            if(dian[i]->x!=dian[j]->x)getline(dian[i],dian[j]);
        }
    }
//    int ans=line.size();
    cout<<ans+20;
    return 0;
}