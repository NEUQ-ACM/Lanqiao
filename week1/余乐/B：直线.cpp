#include <cstdio>
#include <cmath> 
using namespace std;
int t;
double K[50001], B[50001];
int main(){
	for(int x1 = 0;x1 <= 19;x1 ++)
		for(int y1 = 0;y1 <= 20;y1 ++)
			for(int x2 = 0;x2 <= 19;x2 ++)
				for(int y2 = 0;y2 <= 20;y2 ++)
					if(x1 != x2 && y1 != y2){
						double k = (double)(y1 - y2) / (x1 - x2);
						double b = (double)(y1 - k * x1);
						int pd = 1;
						for(int i = 1;i <= t;i ++)
							if(fabs(K[i] - k) < 1e-6 && fabs(B[i] - b) < 1e-6){
								pd = 0;
								break;
							}
						if(pd){
							K[++ t] = k;
							B[t] = b;
						}
					}
	printf("%d", t + 41);
	return 0;
} 
