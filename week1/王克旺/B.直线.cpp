#include<bits/stdc++.h>
using namespace std;
struct node
{
	double k;
	double b;
};
bool cmp(node x,node y)
{
	if(x.k!=y.k)
	{
		return x.k<y.k;
	}
	else
	{
		return x.b<y.b;
	}
}
node p[200000];
int main()
{
	int n=0,x1,y1,x2,y2;  
	for(x1=0;x1<20;x1++)
	{
		for(y1=0;y1<21;y1++)
		{
			for(x2=0;x2<20;x2++)
			{
				for(y2=0;y2<21;y2++)
				{
					if(x1!=x2)
					{
		                double k=(double)(y2-y1)/(x2-x1);
		                double b=y1-k*x1;
		                p[n].k=k;
		                p[n].b=b;
		                n++;
		            }
				}	
			}	
		}	
	}
	sort(p,p+n,cmp);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		if(fabs(p[i].k-p[i-1].k)>1e-8||fabs(p[i].b-p[i-1].b)>1e-8)
		{
			sum++;
		}
	}
	cout<<sum+20;
	return 0; 
}
