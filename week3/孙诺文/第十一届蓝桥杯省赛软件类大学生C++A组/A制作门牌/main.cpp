#include<iostream>
#include<cmath>
using namespace std;

int main()
{
   int sum=0,t;
   for(int i=1;i<=2020;i++)
   {
       t=i;
       while(t!=0)
       {
           if((t%10)==2) sum++;
           t=t/10;
       }
   }
   cout<<sum;
}
