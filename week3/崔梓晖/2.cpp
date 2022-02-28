#include <bits/stdc++.h> 
using namespace std;
 int s=123456789,t=876543219;
int dir[4]={-2,-1,1,2},a[10]; 
bool index[1000000000];  
int num(int a[])
{
	int sum=0;
	for(int i=0;i<9;i++)
	{
		sum*=10;
		sum+=a[i];
	}
	return sum;
}
int main()
{
	int find=0;
	queue<int>q_index;   
	queue<int>q_step;   
	memset(index,0,sizeof(index));
	index[s]=1;
	q_index.push(s);
	q_step.push(1); 
	while(find!=1)
	{
		int x=q_index.front();
		int cnt=q_step.front();
		int k=8,temp;
		while(x>0)
		{
			if(x%10==9)
				temp=k;   
			a[k--]=x%10;
			x/=10;
		}
		for(int i=0;i<4;i++)
		{
			swap(a[temp],a[(temp+dir[i]+9)%9]);
			int j=num(a);
			if(!index[j])
			{
				if(j==t)
				{
					find=1;
					cout<<cnt<<endl;
				}
				index[j]=1;
				q_index.push(j);
				q_step.push(cnt+1);
			}
			swap(a[temp],a[(temp+dir[i]+9)%9]);
		}
		q_index.pop();
		q_step.pop(); 
	}
	return 0;
}
