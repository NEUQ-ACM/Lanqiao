/*
Author: xzc
2019/4/5
2019��ʮ�����ű�ʡ��C++A�� I���ǹ�
ǰ�᳤Y_Cl���԰��Ҷ��ĵģ�AC��~ 
*/
#include <bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define Mst(a,b) memset(a,(b),sizeof(a))
using namespace std;
int dp[1<<20]; //������״̬ѹ�� 
int a[105];
int main()
{
	//freopen("in.txt","r",stdin);
	int m,n,k;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		set<int> v; //��¼n���������ǹ��������� 
		memset(dp,0x3f,sizeof(int)*(1<<m)); //��ʼ�� 
		dp[0] = 0;
		For(i,1,n)
		{
			int x = 0,y;
			For(j,1,k)
			{
				scanf("%d",&y);
				--y;
				v.insert(y);
				x |= (1<<y);
			}
			a[i] = x; //x�Ķ�������ʽ��iλΪ1��������������е�i+1���ǹ� 
			dp[x] = 1;//����״ֻ̬��Ҫ��i���ǹ�1���Ϳ��Դﵽ 
		}
		if((int)v.size()<m) //��n���ƶ�����Ҳ�Բ���m���ǹ� 
		{
			printf("-1\n");continue;
		}
		int ed = (1<<m)-1; //Ŀ��״̬ 
		For(i,1,n)
		{
			For(state,0,ed)
			{
				if(dp[state]>200) continue; //�����е�״̬ȥ���¼��ϵ�i���ǹ����״̬ 
				int to = a[i]|state;
				dp[to] = min(dp[to],1+dp[state]);
			}
		}
		printf("%d\n",dp[ed]); 
	}
	
	return 0;
}