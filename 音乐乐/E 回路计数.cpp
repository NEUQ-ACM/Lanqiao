#include<bits/stdc++.h>
using namespace std;
const int N=21,M=1<<N;
long long road[N][N],f[M][N];

int main()
{
	for(int i=0;i<N;i++)
	    for(int j=0;j<N;j++)
   	       if(__gcd(i+1,j+1)==1)
			    road[i][j]=1; 
	  f[1][0]=1;//����Ϊ{1},ͣ���ڵ�1���������д������һ�ʵڶ�άΪ0��
	for(int i=0;i<(1<<N);i++)//����״̬
	    for(int j=0;j<N;j++)//�߹���ǰ���������ͣ���ڵ�j
	        if(i>>j&1)//��j����û�е����ڲ��ڱ���i����ļ���S�У�������Ϊ�������
	            for(int k=0;k<N;k++)//Ҫ����k��
	                if(!(i>>k&1))//k����S��
	                	if(road[j][k])
							f[i|(1<<k)][k]+=f[i][j];
	long long ans=0;
	for(int i=0;i<N;i++)
		ans+=f[(1<<N)-1][i];//ȫ����Ӧ�ı���Ϊ(1<<N)-1,����iȫѭ��һ������Ϊ��ѧ¥1�����н�ѧ¥������
	cout<<ans<<endl;
	return 0;
}
