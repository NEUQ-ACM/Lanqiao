#include<iostream>
#include<math.h>
using namespace std;
double lenth(double x1,double y1,double x2,double y2);
double heron(double l1,double l2,double l3);
int main()
{
	double x1=2.3,y1=2.5;
	double x2=6.4,y2=3.1;
	double x3=5.1,y3=7.2;
	double l1=lenth(x1,y1,x2,y2);
	double l2=lenth(x1,y1,x3,y3);
	double l3=lenth(x2,y2,x3,y3);
	double area=heron(l1,l2,l3);
	printf("%.3lf",area);
	return 0;
}
double lenth(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double heron(double l1,double l2,double l3)
{
	double p=(l1+l2+l3)/2;
	return sqrt(p*(p-l1)*(p-l2)*(p-l3));
}
